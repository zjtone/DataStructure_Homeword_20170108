#include"stack.h"
template<class T>
Stack<T>::Stack(){
	maxSize = 40;
	first = new T[maxSize];
	top = -1;
	if(first == NULL)exit(0);
}

//默认大小不够用的情况
template<class T>
void Stack<T>::Bigger(){
	T *temp = new T[maxSize + increase];
	for(int i = 0 ; i < maxSize ; i++){
		temp[i] = first[i];
	}
	maxSize += increase;
	first = temp;
}

template<class T>
bool Stack<T>::IsEmpty(){
	return (top == -1);
}
/*
template<class T>
bool Stack<T>::Push(T &x){
	if(top == maxSize - 1)Bigger();
	first[++top] = x;
	return true;
}*/

template<class T>
bool Stack<T>::Push(T x){
	if(top == maxSize - 1)Bigger();
	first[++top] = x;
	return true;
}

template<class T>
bool Stack<T>::Pop(T &x){
	if(top == -1)return false;
	x = first[top--];
	return true;
}
/*
template<class T>
bool Stack<T>::Pop(T x){
	if(top == -1)return false;
	x = first[top--];
	return true;
}*/

template<class T>
bool Stack<T>::Pop(){
	if(top == -1)return false;
	top--;
	return true;
}

template<class T>
void Stack<T>::makeEmpty(){
	top = -1;
}

template<class T>
bool Stack<T>::getTop(T &x){
	if(first == NULL)return false;
	x = first[top];
	return true;
}

template<class T>
T Stack<T>::getTop(){
	if(first == NULL)return NULL;
	return first[top];
}