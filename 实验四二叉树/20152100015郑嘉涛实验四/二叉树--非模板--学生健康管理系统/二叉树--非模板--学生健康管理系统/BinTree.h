#ifndef _BINTREE_H
#define _BINTREE_H
#include<fstream>
#include<stack>
#include"BinTreeNode.h"
class BinTree{
public:
	BinTree(BinTreeNode *temp = NULL){
		root = temp;
	}
	~BinTree(){}
	//ʹ��ǰ���������������  ,sig�Ǵ���յı�־
	void createByFront(BinTreeNode *&root , Student *s , char *sig , int &i);
	void createByFront(Student *s ,int n = 0){
		char *sig = "00000000000";
		createByFront(root , s , sig , n);
	}
	//�ݹ�  ǰ�����򡢺������
	void visitByFrontCycle(BinTreeNode *temp);
	void visitByFrontCycle(){
		visitByFrontCycle(root);
	}
	void visitByMiddleCycle(BinTreeNode *temp);
	void visitByMiddleCycle(){
		visitByMiddleCycle(root);
	}
	void visitByLastCycle(BinTreeNode *temp);
	void visitByLastCycle(){
		visitByLastCycle(root);
	}
	//�ǵݹ�    ǰ�����򡢺������
	void visitByFront();
	void visitByMiddle();
	void visitByLast();
	//������
	int getHeight(){
		return getHeight(root);
	}
	int getHeight(BinTreeNode *root);
	//��Ҷ�ӽڵ���
	int countLeaf(){
		int n = 0;
		countLeaf(root , n);
		return n;
	}
	void countLeaf(BinTreeNode *root , int &n);
	int count(){
		int n = 0;
		count(root , n);
		return n;
	}
	void count(BinTreeNode *root , int &n);
	//���������
	void display(){
		int n = 0;
		display(root , n);
	}
	void display(BinTreeNode *root , int n);

	//ѧ��    ��ز���
	//����
	bool insert(BinTreeNode *root , Student *s);
	bool insert(Student *s){
		return insert(root , s);
	}
	//ɾ��
	bool del(BinTreeNode *&tree , char *s , BinTreeNode *temp);
	bool del(char *s){
		BinTreeNode *temp = NULL;
		return del(root , s , temp);
	}
	//�ļ���ȡ
	bool readFromFile(BinTreeNode *&root , char *ad);
	bool readFromFile(){
		char *a = "C:\\student.txt";
		return readFromFile(root , a);
	}
	//�ļ�д��
	bool writeToFile(BinTreeNode *root , char *ad);
	bool writeToFile(){
		char *a = "C:\\student.txt";
		return writeToFile(root , a);
	}
	//��ѯ
	bool search(BinTreeNode *root , char *id);
	bool search(char *id){
		return search(root , id);
	}
private:
	BinTreeNode *root;
};
#endif