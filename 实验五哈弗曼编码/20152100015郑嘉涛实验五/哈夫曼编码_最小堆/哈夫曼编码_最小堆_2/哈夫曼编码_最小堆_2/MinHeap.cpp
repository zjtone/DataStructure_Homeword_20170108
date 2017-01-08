#include"MinHeap.h"
template<class T>
void MinHeap<T>::siftDown(int start , int end){
	//这里的end 是取得到的
	T temp = heap[start];
	T test;
	bool b = false;
	int i = start , j = 2*i;
	for(; j <= end ;){
		for(int x = 1 ; x <= end ; x++)
			test = heap[x];
		if(j < end && heap[j] > heap[j+1])j++;
		b = (temp < heap[j]);
		if(temp < heap[j])break;
		heap[i] = heap[j];
		i = j;
		j = 2*i;
	}
	heap[i] = temp;
}

template<class T>
void MinHeap<T>::siftUp(int start){
	T temp = heap[start];
	int i = start , j = i/2;
	T test;
	for(; j > 0 ;){
		for(int x = 1 ; x <= size ; x++)
			test = heap[x];
		if(heap[j] <= temp)break;
		heap[i] = heap[j];
		i = j;
		j = i/2;
	}
	heap[i] = temp;
	//test = heap[i];
	//display();//测试
}

template<class T>
MinHeap<T>::MinHeap(int sz = 0){
	size = 0;
	capacity = new int[sz+20];
	heap = new T[sz+20];
}

template<class T>
MinHeap<T>::MinHeap(T *a , int n){
	size = n;
	capacity = n+20;
	heap = new T[n+20];
	for(int i = 0 ; i < size ; i++)
		heap[i+1] = a[i];
	for(int i = size/2 ; i > 0 ; i--)
		siftDown(i , size);
}

template<class T>
bool MinHeap<T>::Insert(const T x){
	if(IsFull())return false;
	heap[++size] = x;
	siftUp(size);
	return true;
}

template<class T>
bool MinHeap<T>::Remove(T &x){
	if(IsEmpty())return false;
	x = heap[1];
	heap[1] = heap[size];
	size--;
	siftDown(1 , size);
	return true;
}

template<class T>
T MinHeap<T>::remove(){
	if(IsEmpty())return T();
	T x = heap[1];
	heap[1] = heap[size];
	size--;
	siftDown(1 , size);
	return x;
}