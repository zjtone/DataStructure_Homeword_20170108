#ifndef _BINTREENODE_H
#define _BINTREENODE_H

#include<iostream>
using namespace std;
class BinTreeNode{
public:
	BinTreeNode(int _value = -1 , char _key = '0' , BinTreeNode *left = NULL , BinTreeNode *right = NULL , BinTreeNode *p = NULL){
		value = _value;
		leftChild = left;
		rightChild = right;
		parent = p;
		key = _key;
	}
	~BinTreeNode(){
		if(leftChild != NULL)delete leftChild;
		if(rightChild != NULL)delete rightChild;
		if(parent != NULL)delete parent;
	}
	char key;
	int value;
	BinTreeNode *leftChild;
	BinTreeNode *rightChild;
	BinTreeNode *parent;//Œ¥ π”√
};

#endif