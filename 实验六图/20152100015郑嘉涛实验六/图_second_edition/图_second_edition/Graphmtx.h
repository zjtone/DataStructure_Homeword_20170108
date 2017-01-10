#ifndef _GRAPHMTX_H
#define _GRAPHMTX_H
#include<iostream>
#include<fstream>
#include<list>
#include<stack>
#include<queue>
#include"UFSet.h"
#include"Graph.h"
#include"MSTEdgeNode.h"
#include"MinHeap.h"
using namespace std;
//图的邻接矩阵存储
template<class T , class E>
class Graphmtx:public Graph<T , E>{
public:
	Graphmtx(E min , E max , int sz = 30 ){
		maxVertices = sz;
		numVertices = 0;
		numEdges = 0;
		minWeight = min;
		maxWeight = max;
		VerticesList = new T[maxVertices];
		Edge = new E*[maxVertices];
		for(int i = 0 ; i < maxVertices ; i++)
			Edge[i] = new E[maxVertices];
		for(int i = 0 , j = 0 ; i < maxVertices ; i++)
			for(j = 0 ; j < maxVertices ; j++)
				Edge[i][j] = (i == j)?minWeight:maxWeight;
	}
	~Graphmtx(){
		delete []VerticesList;
		delete []Edge;
	}
	virtual T getValue(int i)const{
		if(i >=0 && i < maxVertices)return VerticesList[i];
		return NULL;
	}
	virtual E getWeight(int v1 , int v2)const{
		if(v1 < 0 || v2 < 0 ||
			v1 >= maxVertices || v2 >= maxVertices)
			return maxWeight;
		return Edge[v1][v2];
	}
	virtual E getWeight(T &v1 , T &v2)const{
		return getWeight(getVertexPos(v1) , getVertexPos(v2));
	}
	virtual int getFirstNeightbor(int v)const{
		for(int i = 0 ; i < maxVertices ; i++)
			if(Edge[v][i] != minWeight && Edge[v][i] != maxWeight)return i;
		return -1;
	}
	virtual T getFirstNeightbor(T &t)const{
		int v = getFirstNeightbor(getVertexPos(t));
		if(v != -1)
			return VerticesList[v];
		return NULL;
	}
	virtual int getNextNeightbor(int v , int w)const{
		//找顶点v在点w后的第一个邻接点
		for(w++; w < maxVertices ; w++)
			if(Edge[v][w] != minWeight && Edge[v][w] != maxWeight)return w;
		return -1;
	}
	virtual T getNextNeightbor(T &v , T &w)const{
		int x = getNextNeightbor(getVertexPos(v) , getVertexPos(w));
		if(x != -1)
			return VerticesList[x];
		return NULL;
	}
	//插入点方法、插入边方法、删除点方法、删除边方法
	virtual bool insertVertices(const T& vertex){
		if(GraphFull())return false;
		VerticesList[numVertices++] = vertex;
		return true;
	}
	virtual bool insertEdge(int v1 , int v2 , E cost){
		if(Edge[v1][v2] != maxWeight && Edge[v1][v2] != minWeight)return false;
		Edge[v1][v2] = cost;
		numEdges++;
		if(!hasDirection){
			Edge[v1][v2] = cost;
			numEdges++;
		}
		return true;
	}
	virtual bool insertEdge(T v1 , T v2 , E cost){
		return insertEdge(getVertexPos(v1) , getVertexPos(v2) , cost);
	}
	//暂时不实现删除的方法
	virtual bool removeVertex(int v){
		return false;
	}
	virtual bool removeEdge(int v1 , int v2){
		return false;
	}
	//深度优先搜索
	virtual list<T> DFS(){
		list<T> L;
		bool *visited = new bool[numVertices+1];
		for(int i = 0 ; i < numVertices ; i++)
			visited[i] = false;
		for(int i = 0 ; i < numVertices ; i++)
			if(!visited[i])DFS(VerticesList , visited , L , i);
		delete []visited;
		return L;
	}
	virtual void DFS(T *VerticesList , bool *visited , list<T> &L , int v){
		L.push_back(VerticesList[v]);
		visited[v] = true;
		int w = getFirstNeightbor(getVertexPos(VerticesList[v]));
		while(w != -1){
			if(!visited[w])DFS(VerticesList , visited , L , w);
			w = getNextNeightbor(getVertexPos(VerticesList[v]) , getVertexPos(VerticesList[w]));
		}
	}
	//非递归深度优先搜索
	virtual list<T> DFSstack(){
		list<T> t;
		bool *visited = new bool[numVertices+1];
		for(int i = 0 ; i < numVertices ; i++)
			visited[i] = false;
		for(int i = 0 ; i < numVertices ; i++)
			if(!visited[i])DFSstack(VerticesList , visited , t , i);
		delete []visited;
		return t;
	}
	virtual void DFSstack(T *Vertices , bool *visited , list<T> &t , int i){
		stack<int> s;
		t.push_back(Vertices[i]);
		s.push(i);
		visited[i] = true;
		int temp = i;
		for(; !s.empty() ;){
			temp = getFirstNeightbor(s.top());
			if(temp != -1 && visited[temp]){
				while(temp != -1){
					if(!visited[temp])break;
					temp = getNextNeightbor(s.top() , temp);
				}
			}
			if(temp == -1)s.pop();
			if(temp != -1 && !visited[temp]){
				t.push_back(Vertices[temp]);
				visited[temp] = true;
				s.push(temp);
			}
		}
	}
	//广度优先搜索
	virtual list<T> BFS(){
		list<T> t;
		bool *visited = new bool[numVertices+1];
		for(int i = 0 ; i < numVertices ; i++)
			visited[i] = false;
		for(int i = 0 ; i < numVertices ; i++)
			if(!visited[i])BFS(VerticesList , visited , t , i);
		delete []visited;
		return t;
	}
	virtual void BFS(T * Vertices , bool *visited , list<T> &t , int v){
		queue<int> q;
		q.push(v);
		visited[v] = true;
		t.push_back(Vertices[v]);
		for(int temp = v , w = v ; !q.empty() ;){
			temp = q.front();
			q.pop();
			w = getFirstNeightbor(temp);
			while(w != -1){
				if(!visited[w]){
					visited[w] = true;
					t.push_back(Vertices[w]);
					q.push(w);
				}
				w = getNextNeightbor(temp , w);
			}
		}
	}
	//最小生成树
	//Prim算法
	virtual list<MSTEdgeNode<E>> primTree(){
		list<MSTEdgeNode<E>> m;
		primTree(VerticesList , m);
		return m;
	}
	void primTree(T *VerticesList , list<MSTEdgeNode<E>> &m){
		MinHeap<MSTEdgeNode<E>> heap;
		MSTEdgeNode<E> temp;
		bool *visited = new bool[numVertices+1];
		visited[0] = true;
		for(int w = getFirstNeightbor(0) ; w != -1 ; ){
			temp.tail = w;
			temp.head = 0;
			temp.key = Edge[0][w];
			heap.Insert(temp);
		}//初始化
		for(int i , j , count = 1 ; count != numVertices ; ){
			heap.delMin(temp);
			m.push_back(temp);
			visited[temp.tail] = true;
			count++;
			for(j = temp.tail , temp.head = temp.tail ,
				i = getFirstNeightbor(j) ; i != -1;){
					if(!visited[i]){
						temp.tail = i;
						temp.key = Edge[temp.head][temp.tail];
						heap.Insert(temp);
					}
					i = getNextNeightbor(j , i);
			}
		}
	}
	//Kruskal算法
	virtual list<MSTEdgeNode<E>> KruskalTree(){
		list<MSTEdgeNode<E>> m;
		KruskalTree(VerticesList , m);
		return m;
	}
	virtual void KruskalTree(T *VerticesList , list<MSTEdgeNode<E>> &L){
		//因为使用了这个代表结点是否在建好的最小生成树里面的数组，所以这里不用并查集
		bool *visited = new bool[numVertices+1];
		MinHeap<MSTEdgeNode<E>> heap;
		MSTEdgeNode<E> temp;
		for(int i = 0 , j = 0 ; i < numVertices ; i++){
			temp.head = i;
			for(j = 0 ; j < numVertices ; j++){
				temp.tail = j;
				temp.key = Edge[i][j];
				heap.Insert(temp);
			}
		}//初始化
		for(int i = 0 ; i < numVertices - 1 ;){
			heap.delMin(temp);
			if(!visited[temp.tail] || !visited[temp.head]){
				L.push_back(temp);
				visited[temp.tail] = visited[temp.head] = true;
				i++;
			}
		}
	}
	//拓扑排序
	list<T> topologicalSort(){
		list<T> t;
		if(topologicalSort(VerticesList , t , numVertices))return t;
		return NULL;
	}
	bool topological(T *VerticesList , list<T> &t , int n){
		int count = 0;
		queue<T> q;
		int *num = new int[n];
		memset(num , 0 , n);
		for(int i = 0 , j = 0 ; i < n ; i++){
			for(j = 0 ; j < n ; j++){
				if(Edge[i][j] != minWeight 
					&& Edge[i][j] != maxWeight)
					num[j]++;
			}
		}
		int temp , i;
		while(count < n){
			for(i = 0 ; i < n ; i++){
				if(num[i] == 0){
					q.push(VertivesList[i]);count++;
				}
			}
			temp = q.front();q.pop();
			t.push_back(VerticesList[temp]);
			for(i = 0 ; i < n ; i++)
				if(Edge[temp][i] != minWeight 
					&& Edge[temp][i] != maxWeight)
					num[i]--;
			if(q.empty())return false;
		}
		while(!q.empty()){
			temp = q.front();q.pop();
			t.push_back(VerticesList[temp]);
		}
		return true;
	}
	//单源最短路径
	void ShortestPath(){
		E *dist = new E[numVertices];
		int *path = new int[numVertices];
		ShortestPath(VerticesList , VerticesList[0] , numVertices , *dist , *path);
	}
	void ShortestPath(T *VerticesList , T &v , int end , E *dist , int *path){
		bool *set = new bool[end];
		set[getVertexPos(v)] = true;
		int count = 1;
		for(int i = 0 , j = getVertexPos(v) ; i < end ; i++){
			dist[i] = Edge[j][i];
			path[i] = j;
		}
		E min = dist[0];
		for(int i = 0 , j = 0 , k = 0 ; count < end ;){
			min = maxWeight;
			for(i = 0 ; i < end ; i++){
				if(!set[i] && dist[i] < min){
					min = dist;
					j = i;
				}
			}
			set[j] = true;
			count++;
			k = getFirstNeightbor(j);
			while(k != -1){
				if(dist[k] > dist[j] + Edge[j][k]){
					dist[k] = dist[j] + Edge[j][k];
					path[k] = j;
				}
				k = getNetNeightbor(j , k);
			}
		}
	}
protected:
	T *VerticesList;
	E ** Edge;
	virtual int getVertexPos(T vertex)const{
		for(int i = 0 ; i < numVertices ; i++)
			if(VerticesList[i] == vertex)return i;
		return -1;
	}
};

#endif