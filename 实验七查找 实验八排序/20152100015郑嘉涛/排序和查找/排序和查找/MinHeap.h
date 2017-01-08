#ifndef _MINHEAP_H
#define _MINHEAP_H
//¶ÑÅÅĞò
class MinHeap{
public:
	MinHeap(int sz = 20){
		capacity = sz;
		size = 0;
		heap = new int[capacity];
	}

	MinHeap(int *a , int n){
		size = n;
		capacity = n + 20;
		heap = a;
		for(int i = n/2 ; i > 0 ; i--)
			siftDown(i , size);
	}
	void Remove(int &x){
		if(size == 0)return;
		x = heap[1];
		heap[1] = heap[size];
		size--;
		siftDown(1 , size);
	}

	void HeapSort(){
		for(int x ; size != 0 ;){
			Remove(x);
			heap[size + 1] = x;
		}
	}
protected:
	int *heap;
	int size;
	int capacity;

	void siftUp(int start){
		int i , j;
		int temp = heap[start];
		for(i = start , j = i/2 ; i > 0 ;){
			if(heap[j] < temp){
				heap[i] = heap[j];
			}else
				break;
			i = j;
			j = i/2;
		}
		heap[i] = temp;
	}
	void siftDown(int start , int end){
		int i , j , temp = heap[start];
		for(i = start , j = 2*i ; j <= end ;){
			if(j < end && heap[j] < heap[j+1])j++;
			if(heap[j] < temp)break;
			heap[i] = heap[j];
			i = j;
			j = 2*i;
		}
		heap[i] = temp;
	}
};
#endif