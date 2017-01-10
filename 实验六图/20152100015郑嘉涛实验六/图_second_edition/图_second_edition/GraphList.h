#ifndef _GRAPHLIST_H
#define _GRAPHLIST_H
#include<list>
#include<queue>
#include<stack>
#include"Graph.h"
#include"MSTEdgeNode.h"
//图的邻接表表示
template<class T , class E>
struct Edge{
	//边
	int dest;//结点位置
	E cost;//权值
	Edge<T , E> *next;
	Edge<T , E>(){
		this->dest = 0;
		this->next = NULL;
	}
	Edge<T , E>(int dest , E cost , Edge<T , E> *next){
		this->dest = dest;
		this->cost = cost;
		this->next = next;
	}
};
template<class T , class E>
struct Vertex{
	T data;//结点
	Edge<T , E> *adj;//指向边结点
	Vertex(){}
	Vertex(T data , Edge<T , E> *a){
		this->data = data;
		adj = a;
	}
};

template<class T , class E>
class GraphList : public Graph<T , E>{
public:
	GraphList(E min , E max , int sz = 30){
		maxVertices = sz;
		numVertices = 0;
		numEdges = 0;
		minWeight = min;
		maxWeight = max;
		vertex = new Vertex<T , E>[maxVertices];
	}
	~GraphList(){delete vertex;}
	virtual T getValue(int i)const {
		if(i < 0 || i >= numVertices)return NULL;
		return vertex[i].data;
	}
	virtual E getWeight(int v1 , int v2)const {
		if(v1 < 0 || v1 >= numVertices || v2 <= 0 || v2 >= numVertices)return minWeight;
		if(v1 == v2)return minWeight;
		Edge<T , E> *e = vertex[v1].adj;
		while(e != NULL && e->dest != v2)
			e = e->next;
		if(e == NULL)return maxWeight;
		return e->cost;
	}
	virtual int getFirstNeightbor(int v)const {
		if(v < 0 || v >= numVertices)return -1;
		if(vertex[v].adj == NULL)return -1;
		return vertex[v].adj->dest;
	}
	virtual T getFirstNeightbor(T &v)const {
		int w = getFirstNeightbor(getVertexPos(v));
		if(w != -1)return vertex[w].data;
		return NULL;
	}
	virtual int getNextNeightbor(int v , int w)const {
		if(v < 0 || v >= numVertices)return -1;
		Edge<T , E> *e = vertex[v].adj;
		for(; e != NULL && e->dest != w ; e = e->next);
		if(e == NULL)return -1;
		e = e->next;
		if(e == NULL)return -1;
		return e->dest;
	}
	virtual T getNextNeightbor(T &v , T &w)const {
		int k = getNextNeightbor(getVertexPos(v) , getVertexPos(w));
		if(k != -1)return vertex[k].data;
		return NULL;
	}
	virtual bool insertVertices(const T& vertex){
		if(GraphFull())return false;
		this->vertex[numVertices++] = Vertex<T , E>(vertex , NULL);
		return true;
	}
	virtual bool insertEdge(int v1 , int v2 , E cost){
		if(v1 < 0 || v1 >= numVertices || v2 < 0 || v2 >= numVertices)return false;
		Edge<T , E> *e = vertex[v1].adj;
		for(; e != NULL && e->next != NULL ; e = e->next);
		if(e == NULL)
			vertex[v1].adj = new Edge<T , E>(v2 , cost , NULL);
		else 
			e->next = new Edge<T ,E>(v2 , cost , NULL);
		if(!hasDirection){
			//insertEdge(v2 , v1 , cost);
			e = vertex[v2].adj;
			for(; e != NULL && e->next != NULL ; e = e->next);
			if(e == NULL)
				vertex[v2].adj = new Edge<T , E>(v1 , cost , NULL);
			else 
				e->next = new Edge<T , E>(v1 , cost , NULL);
		}
		return true;
	}
	virtual bool insertEdge(T &v1 , T &v2 , E cost){
		return insertEdge(getVertexPos(v1) , getVertexPos(v2) , cost);
	}
	virtual bool removeVertex(int v){
		return false;
	}
	virtual bool removeEdge(int v1 , int v2){
		return false;
	}
	//以下部分：深度优先搜索（递归、非递归）、广度优先搜索、单源最短路径、拓扑排序、最小生成树（Kruskal、Prim)
	list<T> DFS(){
		list<T> L;
		bool *visited = new bool[numVertices+1];
		for(int i = 0 ; i < numVertices ; visited[i] = false , i++);
		for(int i = 0 ; i < numVertices ; i++){
			if(!visited[i])DFS(vertex , visited , i , L);
		}
		return L;
	}
	void DFS(Vertex<T , E> *vertex , bool *visited , int v ,  list<T> &L){
		L.push_back(vertex[v].data);
		visited[v] = true;
		int w = getFirstNeightbor(v);
		while(w != -1){
			if(!visited[w])DFS(vertex , visited , w , L);
			w = getNextNeightbor(v , w);
		}
	}
	list<T> DFSstack(){
		list<T> L;
		stack<int> s;
		bool *visited = new bool[numVertices + 1];
		for(int i = 0 ; i < numVertices ; visited[i] = false , i++);
		for(int i = 0 , w , v; i < numVertices ; i++){
			if(!visited[i]){
				L.push_back(vertex[i].data);
				visited[i] = true;
				s.push(i);
				while(!s.empty()){
					v = s.top();
					w = getFirstNeightbor(v);
					while(w != -1){
						if(!visited[w]){
							L.push_back(vertex[w].data);
							visited[w] = true;
							s.push(w);
							break;
						}
						w = getNextNeightbor(v , w);
					}
					if(w == -1)s.pop();
				}
			}
		}
		return L;
	}
	list<T> BFS(){
		list<T> L;
		queue<int> q;
		bool *visited = new bool[numVertices+1];
		for(int i = 0 ; i < numVertices ; visited[i] = false , i++);
		L.push_back(vertex[0].data);
		visited[0] = true;
		q.push(0);
		for(int v , w ; !q.empty() ;){
			v = q.front();
			q.pop();
			w = getFirstNeightbor(v);
			while(w != -1){
				if(!visited[w]){
					L.push_back(vertex[w].data);
					visited[w] = true;
					q.push(w);
				}
				w = getNextNeightbor(v , w);
			}
		}
		return L;
	}
	//Kruskal
	list<MSTEdgeNode<E>> KruskalTree(){
		MinHeap<MSTEdgeNode<E>> *heap = new MinHeap<MSTEdgeNode<E>>(numEdges);
		MSTEdgeNode<E> *temp;
		Edge<T , E> *edge;
		list<MSTEdgeNode<E>> L;
		bool *set = new bool[numVertices];
		for(int i = 0 ; i < numVertices ; i++){
			set[i] = false;
			for(edge = vertex[i].adj ; edge != NULL ; edge = edge->next){
				temp = new MSTEdgeNode<E>(i , edge->dest , edge->cost);
				heap->Insert(*temp);
			}
		}//初始化
		temp = new MSTEdgeNode<E>();
		for(int i = 0 ; i < numVertices - 1 ; ){
			heap->Remove(*temp);
			if(!set[temp->head] || !set[temp->tail]){
				L.push_back(*temp);
				i++;
			}
		}
		return L;
	}
	//Prim
	list<MSTEdgeNode<E>> PrimTree(){
		MinHeap<MSTEdgeNode<E>> *heap = new MinHeap<MSTEdgeNode<E>>(numEdges);
		MSTEdgeNode<E> *temp;
		list<MSTEdgeNode<E>> L;
		Edge<T , E> *edge;
		bool set[numVertices];
		edge = vertex[0].adj;
		for(int i = 0 ; i < numVertices ; i++)set[i] = false;
		for(; edge != NULL ; edge = edge->next){
			temp = new MSTEdgeNode<E>(0 , edge->dest , edge->cost);
			heap->Insert(*temp);
		}
		set[0] = true;
		temp = new MSTEdgeNode<E>();
		for(int i = 0 ; i < numVertices ;){
			heap->Remove(*temp);
			if(!set[temp->tail]){
				set[temp->tail] = true;
				L.push_back(temp);
				edge = vertex[temp->tail].adj;
				temp->head = temp->tail;
				for(; edge != NULL ; edge = edge->next){
					temp->tail = edge->dest;
					temp->key = edge->cost;
					heap->Insert(*temp);
				}
				i++;
			}
		}
		return L;
	}
	//单源最短路径  第一个结点与其他结点间的最短路径
	void ShortestPath(int *&dist , int *&path){
		bool set[numVertex];
		Edge<T , E> *edge;
		for(int i = 0 ; i < numVertex ; i++){
			set[i] = false;
			dist[i] = getWeight(0 , i);
			if(dist[i] != maxWeight)
				path[i] = 0;
			else 
				path[i] = -1;
		}//初始化
		set[i] = true;
		E min;
		for(int i = 0 , j , k ; i < numVertex-1 ; i++){
			min = maxWeight;
			k = 0;
			for(j = 1 ; j < numVertex ; j++){
				if(min < dist[j] && !set[j]){
					min = dist[j];
					k = j;
				}
			}
			set[k] = true;
			for(edge = vertex[k].adj ; edge != NULL ; edge = edge->next){
				if(dist[edge->dest] < dist[k] + edge->cost){
					path[edge->dest] = k;
					dist[edge->dest] = dist[k] + edge->cost;
				}
			}
			i++;
		}
	}
	//拓扑排序
	queue<T> TopologicalSort(){
		int *in = new int[numVertices];
		memset(in , 0 , numVertices);
		Edge<T , E> *temp;
		for(int i = 0 ; i < numVertices ; i++){
			temp = vertex[i].adj;
			for(; temp != NULL ; ){
				in[temp->dest]++;
				temp = temp->next;
			}
		}
		stack<int> s;
		queue<T> q;
		for(int i = 0 ; i < numVertices ; i++)
			if(in[i] == 0)s.push(i);
		for(int n ; !s.empty() ;){
			n = s.top();
			s.pop();
			q.push(vertex[n]);
			for(temp = vertex[n].adj ; temp != NULL ; ){
				in[temp->dest]--;
				if(in[temp->dest] == 0)s.push(temp->dest);
				temp = temp->next;
			}
		}
		return q;
	}
protected:
	Vertex<T , E> *vertex;
	virtual int getVertexPos(T v)const{
		for(int i = 0 ; i < numVertices ; i++)
			if(vertex[i].data == v)return i;
		return -1;
	}
};
#endif