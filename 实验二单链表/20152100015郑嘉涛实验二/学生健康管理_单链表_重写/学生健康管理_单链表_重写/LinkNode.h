#ifndef _LINK_NODE_H
#define _LINK_NODE_H

template<class T>
struct LinkNode{
public:
	T data;
	LinkNode<T> *next;
public:
	LinkNode(){next = NULL;}
	LinkNode(T &d , LinkNode<T> *next = NULL){
		data = d;
		this->next = next;
	}
	~LinkNode(){
		if(next != NULL){
			delete next;
		}
	}
	T getData(){
		return data;
	}
	void display(){
		cout<<data;
	}
};

#endif