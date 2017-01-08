#ifndef _BINTREENODE_H
#define _BINTREENODE_H
#include"word.h"
template<class T>
struct BinTreeNode{
	T value;
	BinTreeNode *leftChild;
	BinTreeNode *rightChild;
	BinTreeNode(){
		leftChild = rightChild = NULL;
	}
	BinTreeNode(T v){
		value = v;
		leftChild = rightChild = NULL;
	}
	BinTreeNode(T v , BinTreeNode<T> *left , BinTreeNode<T> *right ){
		value = v;
		leftChild = left;
		rightChild = right;
	}
	bool operator > (BinTreeNode<T> &t){
		return (value > t.value);
	}
	bool operator >= (BinTreeNode<T> &t){
		return (value >= t.value);
	}
	bool operator < (BinTreeNode<T> &t){
		return (value < t.value);
	}
	bool operator <= (BinTreeNode<T> &t){
		return (value <= t.value);
	}
	bool operator == (BinTreeNode<T> &t){
		return (value == t.value);
	}
	/*
	BinTreeNode<T> operator = (BinTreeNode<T> &t){
		value = t.value;
		leftChild = t.leftChild;
		rightChild = t.rightChild;
		return BinTreeNode<T>(value , leftChild , rightChild);
	}*/
	BinTreeNode<T> operator = (const BinTreeNode<T> &m){
		value = m.value;
		leftChild = m.leftChild;
		rightChild = m.rightChild;
		return BinTreeNode<T>(value , leftChild , rightChild);
	}
	T operator + (BinTreeNode<T> &t){
		return (value + t.value);
	}

	friend ostream &operator <<(ostream &out , BinTreeNode<T> *&t){
		out<<t->value;
		return out;
	}
	friend ostream &operator <<(ostream &out , BinTreeNode<T> &t){
		out<<t.value;
		return out;
	}
};

#endif