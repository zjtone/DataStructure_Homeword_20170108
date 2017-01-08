#ifndef _HFMTREE_H
#define _HFMTREE_H
#include<fstream>
#include<iostream>
#include"BinTreeNode.h"
#include"MinHeap.h"
#include"MinHeap.cpp"
using namespace std;
template<class T>
class hfmTree{
public:
	hfmTree(){root = NULL;}
	hfmTree(T *t , int n){
		create(t , n);
	}

	void create(T *t , int n){
		BinTreeNode<T> *roots = new BinTreeNode<T>[n];
		for(int i = 0 ; i < n ; i++)
			roots[i] = *new BinTreeNode<T>(t[i]);
		MinHeap<BinTreeNode<T>> *heap = new MinHeap<BinTreeNode<T>>(roots , n);
		BinTreeNode<T> rt;
		BinTreeNode<T> *left , *right;
		T temp;
		for(;;){
			//heap->display();
			left = new BinTreeNode<T>();
			right = new BinTreeNode<T>();
			heap->Remove(*left);
			root = left;
			if(heap->IsEmpty())break;
			heap->Remove(*right);
			temp = left->value + right->value;
			rt = *new BinTreeNode<T>(temp , left , right);
			//root = &rt;
			heap->Insert(rt);
		}
		//heap->display();
		cout<<endl;
		//delete roots;
	}

	void display(){
		display(root , 1);
	}
	void display(BinTreeNode<T> *root , int n){
		if(root == NULL)return;
		for(int i = 0 ; i < n ; i++)
			cout<<"    ";
		cout<<root->value<<endl;
		n++;
		display(root->leftChild , n);
		display(root->rightChild , n);
		n--;
	}
protected:
	BinTreeNode<T> *root;
};

#endif