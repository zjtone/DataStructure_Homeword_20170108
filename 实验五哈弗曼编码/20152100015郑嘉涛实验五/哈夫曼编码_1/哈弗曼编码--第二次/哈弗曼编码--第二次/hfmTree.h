#ifndef _HFMTREE_H
#define _HFMTREE_H
#include<fstream>
#include<stack>
#include"BinTreeNode.h"
#include"Code.h"
//直接在这个类里面实现编码操作和二叉树操作
class hfmTree{
public:
	hfmTree(BinTreeNode *_root = NULL){root = _root;}
	~hfmTree(){
		if(root != NULL)delete root;
		if(code != NULL)delete code;
		if(word != NULL)delete word;
	}
	bool create(BinTreeNode *&root , char *key , int *value , int n);
	bool create(char *key , int *value , int  n){
		if(value == NULL)return false;
		if(key == NULL)return false;
		code = new Code[n];
		word = new char[n+1];
		word[n] = '\0';
		this->n = n;
		return create(root , key , value , n);
	}
	//传入指针数组，按照节点值大小排序
	friend void chooseSortTree(BinTreeNode **t , int i , int n);
	void display(BinTreeNode *root , int n = 0);
	void display(){
		display(root , 0);
	}
	void show(){
		for(int i = 0 ; i < n ; i++){
			cout<<code[i].getCode()<<"  "<<word[i]<<endl;
		}
	}
	//文件操作
	//将二叉树按照前序遍历写入文件
	bool writeToFile(BinTreeNode *root , ofstream &out);
	bool writeToFile(){
		if(root == NULL)return false;
		ofstream out("C:\\hfmTree.txt");
		if(!out)return false;
		bool flag = writeToFile(root , out);
		out.close();
		return flag;
	}

	//将文件中的值按照前序遍历还原成二叉树
	bool readFromFile(BinTreeNode *&root , ifstream &in , int &n);
	bool readFromFile(){
		ifstream in("C:\\hfmTree.txt");
		if(!in)return false;
		int n = 0;
		bool flag = readFromFile(root , in , n);
		code = new Code[n];
		word = new char[n+1];
		this->n = n;
		in.close();
		return flag;
	}

	bool hasTree(){
		return root != NULL;
	}
	BinTreeNode *getRoot(){
		return root;
	}

	void encoding(BinTreeNode *root , Code *code , Code &temp  , char *word , int &i);
	void encoding(){
		if(root == NULL){
			readFromFile();
		}
		Code temp;
		int n = 0;
		encoding(root , code , temp , word , n);
	}

	int getLocation(char *word , char ch , int n);
	int getLocation(char ch , int n){
		return getLocation(word , ch , n);
	}
	int getLocation(Code *code , Code ch , int n);
	int getLocation(Code ch){
		return getLocation(code , ch , n);
	}

	void write(ofstream &out , Code t);
	void write(Code t){
		ofstream out("C:\\CodeFile.txt" , ios::app);
		if(!out)return;
		write(out , t);
		out.close();
	}

	void codeFile(ifstream &in , char ch);
	void codeFile(){
		char ch = ' ';
		ofstream out("C:\\CodeFile.txt");
		out.close();
		ifstream in("C:\\ToBeTran.txt");
		if(!in)return;
		codeFile(in , ch);
		in.close();
	}

	void decodeFile(ofstream &out , ifstream &in);
	void decodeFile(){
		if(root == NULL)readFromFile();
		ofstream out("C:\\TextFile.txt");
		if(!out)return;
		ifstream in("C:\\CodeFile.txt");
		if(!in)return;
		decodeFile(out , in);
		out.close();
		in.close();
	}
private:
	BinTreeNode *root;
	Code *code;
	char *word;
	int n;
};

#endif