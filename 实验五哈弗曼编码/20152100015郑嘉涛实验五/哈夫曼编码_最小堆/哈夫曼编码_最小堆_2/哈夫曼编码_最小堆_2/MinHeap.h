//×îÐ¡¶Ñ
#ifndef _MINHEAP_H
#define _MINHEAP_H
#include<iostream>
#include"BinTreeNode.h"
using namespace std;
template <class T>
class MinHeap{
public:
	MinHeap<T>(int sz = 0);
	MinHeap<T>(T *a , int n);
	~MinHeap(){delete []heap;}
	bool Insert(const T x);
	bool Remove(T &x);
	T remove();
	bool IsEmpty()const{
		return (size == 0);
	}
	bool IsFull()const{
		return (size == capacity);
	}
	void makeEmpty(){
		size = 0;
	}
	void display(){
		for(int i = 1 ; i <= size ; i++)
			cout<<heap[i]<<"  ";
		cout<<endl;
	}
private:
	T *heap;
	int size;
	int capacity;
	void siftDown(int start , int end);
	void siftUp(int start);
};

#endif