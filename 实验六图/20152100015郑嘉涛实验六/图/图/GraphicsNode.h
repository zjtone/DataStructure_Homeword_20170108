#ifndef _GRAPHICSNODE_H
#define _GRAPHICSNODE_H
#include<iostream>
using namespace std;
//ͼ���ڽӱ��ʾ
struct GraphNode{
	int key;
	GraphNode *next;
	GraphNode(int key = -1 , GraphNode *next = NULL){
		this->key = key;
		this->next = NULL;
	}
};

#endif