#ifndef _GRAPH_H
#define _GRAPH_H
//图的抽象基类
//enum boolean{FALSE , TRUE};
template<class T , class E>
class Graph{
public:
	Graph<T,E>(){}
	Graph<T,E>(E max , E min , int sz = 30){
		maxVertices = sz;
		maxWeight = max;
		minWeight = min;
	}
	~Graph<T,E>(){}
	virtual bool GraphEmpty()const{
		if(numVertices == 0)return true;
		return false;
	}
	virtual bool GraphFull()const{
		if(numVertices == maxVertices)return true;
		if(numEdges == (maxVertices-1)*maxVertices/2)return true;
		return false;
	}
	virtual int NumberOfVertices(){return numVertices;}
	virtual int NumberOfEdges(){return numEdges;}
	virtual T getValue(int i)const =0;
	virtual E getWeight(int v1 , int v2)const =0;
	virtual int getFirstNeightbor(int v)const =0;
	virtual int getNextNeightbor(int v , int w)const =0;
	virtual bool insertVertices(const T& vertex)=0;
	virtual bool insertEdge(int v1 , int v2 , E cost)=0;
	virtual bool removeVertex(int v)=0;
	virtual bool removeEdge(int v1 , int v2)=0;
	virtual void setDirection(bool d){hasDirection = d;}
protected:
	E maxWeight;
	E minWeight;
	int maxVertices;
	int numEdges;
	int numVertices;
	bool hasDirection;
	virtual int getVertexPos(T vertex)const = 0;
};

#endif