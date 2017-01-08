#ifndef _GRAPHICS_H
#define _GRAPHICS_H
#include<fstream>
#include<iostream>
#include<queue>
#include"GraphicsNode.h"
using namespace std;
//图的邻接表表示
class Graphics{
private:
	GraphNode *start;
	char *word;//代表结点的值
	int n;//结点个数
	bool direction;//代表是否有向图，默认无向图。
	int **key;//邻接矩阵
public:
	Graphics(GraphNode *start = NULL){
		this->start = start;
		direction = false;
		n = 0;
		word = NULL;
	}

	void readFile(ifstream &in);
	void readFile(char *ad){
		ad = "C:\\g.txt";
		if(ad == NULL)return;
		ifstream in(ad);
		if(!in){
			cerr<<"文件不存在或者路径错误！"<<endl;
			return;
		}
		readFile(in);
	}

	//深度优先搜索
	void DFS(GraphNode *start , bool *visited , int i);
	void DFS(){
		bool *visited = new bool[n];
		for(int i = 0 ; i < n ; i++ , visited[i] = false);
		DFS(start , visited , start[0].key);
	}

	//使用队列完成广度优先搜索
	void BFSQueue(GraphNode *start , bool *visited);
	void BFSQueue(){
		bool *visited = new bool[n];
		for(int i = 0 ; i < n ; i++)visited[i] = false;
		BFSQueue(start , visited);
	}

	int getLocation(char ch);
};
#endif