#ifndef _GRAPHICS_H
#define _GRAPHICS_H
#include<fstream>
#include<iostream>
#include<queue>
#include"GraphicsNode.h"
using namespace std;
//ͼ���ڽӱ��ʾ
class Graphics{
private:
	GraphNode *start;
	char *word;//�������ֵ
	int n;//������
	bool direction;//�����Ƿ�����ͼ��Ĭ������ͼ��
	int **key;//�ڽӾ���
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
			cerr<<"�ļ������ڻ���·������"<<endl;
			return;
		}
		readFile(in);
	}

	//�����������
	void DFS(GraphNode *start , bool *visited , int i);
	void DFS(){
		bool *visited = new bool[n];
		for(int i = 0 ; i < n ; i++ , visited[i] = false);
		DFS(start , visited , start[0].key);
	}

	//ʹ�ö�����ɹ����������
	void BFSQueue(GraphNode *start , bool *visited);
	void BFSQueue(){
		bool *visited = new bool[n];
		for(int i = 0 ; i < n ; i++)visited[i] = false;
		BFSQueue(start , visited);
	}

	int getLocation(char ch);
};
#endif