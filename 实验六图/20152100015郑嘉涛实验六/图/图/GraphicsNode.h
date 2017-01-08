#ifndef _GRAPHICSNODE_H
#define _GRAPHICSNODE_H
#include<iostream>
using namespace std;
//图的邻接表表示
struct GraphNode{
	int key;
	GraphNode *next;
	GraphNode(int key = -1 , GraphNode *next = NULL){
		this->key = key;
		this->next = NULL;
	}
};

#endif