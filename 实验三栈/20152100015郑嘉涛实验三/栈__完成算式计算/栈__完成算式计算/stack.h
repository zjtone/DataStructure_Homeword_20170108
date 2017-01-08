#ifndef _STACK_H
#define _STACK_H

const int increase = 20;
#include<iostream>
using namespace std;
template <class T>
class Stack{
public :
	Stack();
	~Stack(){
		delete []first;
	}
//	bool Push(T &x);
	bool Push(T x);
	bool Pop(T &x);
	bool Pop();
	bool IsEmpty();
	void makeEmpty();
	bool getTop(T &x);
	T getTop();
private:
	T *first;
	int maxSize;
	int top;
	void Bigger();
};
#endif