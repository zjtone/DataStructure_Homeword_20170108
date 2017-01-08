#ifndef _BINTREENODE_H
#define _BINTREENODE_H
#include"student.h"
struct BinTreeNode{
	BinTreeNode *leftChild , *rightChild;
	Student data;

	BinTreeNode(){
		leftChild  = rightChild = NULL;
	}

	BinTreeNode(Student &s , BinTreeNode *temp = NULL , BinTreeNode *temp2 = NULL){
		data = s;
		leftChild = temp;
		rightChild = temp2;
	}
};
#endif