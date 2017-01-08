#ifndef _SORT_H
#define _SORT_H
//排序
#include<iostream>
#include<stack>
using namespace std;
void qsortUp(int *a , int start , int end){
	if(start < end){
		int i , j , temp;
		for(i = start , j = start , temp ; i < end ; i++){
			if(a[i] < a[start]){
				j++;
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
		temp = a[j];
		a[j] = a[start];
		a[start] = temp;
		qsortUp(a , start , j);
		qsortUp(a , j + 1 , end);
	}
}
void qsortDown(int *a , int start , int end){
	if(start < end){
		int i , j , temp;
		for( i = j = temp = start ; i < end ; i++){
			if(a[i] > a[start]){
				j++;
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
		temp = a[j];
		a[j] = a[start];
		a[start] = temp;
		qsortDown(a , start , j);
		qsortDown(a , j + 1 , end);
	}
}
//尝试使用非递归进行快速排序
void qosrtStack(int *a , int n){
	stack<int> start;
	stack<int> end;
	start.push(0);end.push(n);
	int first , last;
	for(int i , j , temp; !start.empty() && !end.empty() ;){
		first = start.top();
		start.pop();
		last = end.top();
		end.pop();
		if(first < last){
			for(i = first , j = first ; i < last ; i++){
				if(a[i] < a[first]){
					j++;
					temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
			}
			temp = a[j];
			a[j] = a[first];
			a[first] = temp;
			start.push(first);end.push(j);
			start.push(j + 1);end.push(last);
		}
	}
}

void chooseSort(int *a , int n){
	for(int i = 0 , j = i , temp ; i < n ; i++){
		for(j = i + 1 ; j < n ; j++){
			if(a[i] > a[j]){
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

void bubbleSort(int *a , int n){
	for(int i = 0 , j = 0 , temp ; i < n ; i++){
		for(j = n - 1 ; j > 0 ; j--){
			if(j[a] < (j-1)[a]){
				temp = (j-1)[a];
				(j-1)[a] = j[a];
				j[a] = temp;
			}
		}
	}
}

void insertSort(int *a , int n){
	for(int i = 0 , j = 0 , temp ; i < n ; i++){
		temp = a[i];
		for(j = i ; j > 0 ; j--){
			if(a[j-1] < temp)break;
			a[j] = a[j-1];
		}
		a[j] = temp;
	}
}
#endif