#ifndef _MINHEAP_H
#define _MINHEAP_H
template<class T>
class MinHeap{
public:
	MinHeap<T>(int _c = 50){
		size = 0;
		capacity = _c;
		heap = new T[capacity];
	}
	MinHeap<T>(T *t , int sz){
		size = sz;
		capacity = sz + 30;
		heap = new T[capacity];
		for(int i = 1 ; i <= sz ; i++)
			heap[i] = t[i];
		for(int i = size/2 ; i > 0 ; i--)
			siftDown(i , size);
	}
	~MinHeap(){
		delete []heap;
	}
	bool IsFull()const{
		return (size == capacity);
	}
	bool IsEmpty(){
		return (size == 0 && capacity == 0);
	}
	bool Insert(T in){
		if(IsFull())return false;
		heap[++size] = in;
		siftUp(size);
		return true;
	}
	bool delMin(T &min){
		if(IsEmpty())return false;
		min = heap[1];
		heap[1] = heap[size--];
		siftDown(1 , size);
		return true;
	}
protected:
	void siftDown(int start , int end){
		T temp = heap[start];
		int i = start , j = 2*i;
		for(; j < end;){
			if(heap[j] > heap[j+1])j++;
			if(temp < heap[j])break;
			heap[i] = heap[j];
			i = j;
			j = 2*i;
		}
		heap[i] = temp;
	}
	void siftUp(int start){
		int i = start , j = i/2;
		T temp = heap[start];
		for(; j > 0 ;){
			if(temp > heap[j])break;
			heap[i] = heap[j];
			i = j;
			j = i/2;
		}
		heap[i] = temp;
	}
	T *heap;
	int size;
	int capacity;
};
#endif