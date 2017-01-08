#ifndef _BINTREENODE_H
#define _BINTREENODE_H
#include<iostream>
using namespace std;
class BinTreeNode{
public:
	int value;
	BinTreeNode *left , *right;
	BinTreeNode(int value = 0 , BinTreeNode *left = NULL , BinTreeNode *right = NULL){
		this->value = value;
		this->left = left;
		this->right = right;
	}
	bool operator < (BinTreeNode &b){
		return (value < b.value);
	}
	bool operator <= (BinTreeNode &b){
		return (value <= b.value);
	}
	bool operator > (BinTreeNode &b){
		return (value > b.value);
	}
	bool operator >= (BinTreeNode &b){
		return (value >= b.value);
	}
	bool operator == (BinTreeNode &b){
		return (value == b.value);
	}
};
#endif