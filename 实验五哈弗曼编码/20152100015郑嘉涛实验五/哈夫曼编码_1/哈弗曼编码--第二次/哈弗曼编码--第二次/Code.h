#ifndef _CODE_H
#define _CODE_H
#include<fstream>
#include"BinTreeNode.h"
class Code{
public:
	Code(int n = 0){
		code = new char[n+1];
		code[n] = '\0';
		this->n = n;
	}
	void add(char ad){
		n++;
		char *newCode = new char[n+1];
		for(int i = 0 ; i < n-1 ; i++)
			newCode[i] = code[i];
		newCode[n-1] = ad;
		code = newCode;
		code[n] = '\0';
	}
	void del(){
		if(n == 0)return ;
		char *newCode = new char[n];
		for(int i = 0 ; i < n-1 ; i++)
			newCode[i] = code[i];
		code = newCode;
		code[n-1] = '\0';
		n--;
	}
	void show(){
			cout<<code;
	}
	int getN(){
		return n;
	}
	char* getCode(){
		return code;
	}
	void clear(){
		delete code;
		code = new char[0];
		n = 0;
	}
private:
	int n;
	char *code;
};


#endif