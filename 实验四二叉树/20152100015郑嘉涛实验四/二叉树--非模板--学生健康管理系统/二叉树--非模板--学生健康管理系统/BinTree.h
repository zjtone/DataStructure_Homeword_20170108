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
	//使用前序遍历建立二叉树  ,sig是代表空的标志
	void createByFront(BinTreeNode *&root , Student *s , char *sig , int &i);
	void createByFront(Student *s ,int n = 0){
		char *sig = "00000000000";
		createByFront(root , s , sig , n);
	}
	//递归  前序、中序、后序遍历
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
	//非递归    前序、中序、后序遍历
	void visitByFront();
	void visitByMiddle();
	void visitByLast();
	//求树高
	int getHeight(){
		return getHeight(root);
	}
	int getHeight(BinTreeNode *root);
	//求叶子节点数
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
	//输出二叉树
	void display(){
		int n = 0;
		display(root , n);
	}
	void display(BinTreeNode *root , int n);

	//学生    相关操作
	//插入
	bool insert(BinTreeNode *root , Student *s);
	bool insert(Student *s){
		return insert(root , s);
	}
	//删除
	bool del(BinTreeNode *&tree , char *s , BinTreeNode *temp);
	bool del(char *s){
		BinTreeNode *temp = NULL;
		return del(root , s , temp);
	}
	//文件读取
	bool readFromFile(BinTreeNode *&root , char *ad);
	bool readFromFile(){
		char *a = "C:\\student.txt";
		return readFromFile(root , a);
	}
	//文件写入
	bool writeToFile(BinTreeNode *root , char *ad);
	bool writeToFile(){
		char *a = "C:\\student.txt";
		return writeToFile(root , a);
	}
	//查询
	bool search(BinTreeNode *root , char *id);
	bool search(char *id){
		return search(root , id);
	}
private:
	BinTreeNode *root;
};
#endif