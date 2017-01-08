#ifndef _HFMCODE_H
#define _HFMCODE_H
#include<list>
#include"hfmTree.h"
#include"word.h"
class hfmCode:public hfmTree<word>{
public:
	void init(word *w , int n){
		size = n;
		create(w , n);
		ofstream out("C:\\hfmTree.txt");
		if(!out)return;
		out<<n<<"n"<<endl;
		for(int i = 0 ; i < n ; i++){
			out<<w[i].ch<<"$"<<w[i].value<<"#";
		}
		out.close();
	}
	void readTree(){
		ifstream in("C:\\hfmTree.txt");
		if(!in)exit(0);
		char ch;
		in.get(ch);
		int n = 0;
		for(; ch != 'n' ; ){
			n = n*10 +(ch-48);
			in.get(ch);
		}
		word *w = new word[n];
		in.get(ch);
		in.get(ch);
		for(int i = 0 , j = 0 ; i < n ; i++){
			while(ch != '$'){//???
					w[i].ch = ch;
					in.get(ch);
			}
			in.get(ch);
			while(ch != '#'){
				j = j*10 + (ch-48);
				in.get(ch);
			}
			w[i].value = j;
			j = 0;
			in.get(ch);
		}
		for(int i = 0 ; i < n ; i++)
			cout<<w[i]<<"  ";
		cout<<endl;
		in.close();
		create(w , n);
	}
	bool encode(char *ToBeTran , char *CodeFile){
		if(root == NULL){
			readTree();
			if(root == NULL)return false;
		}
		ifstream in(ToBeTran);
		ofstream out(CodeFile);
		if(!in || !out)return false;
		list<int> q;
		q.clear();
		char ch;
		int n;
		for(;;){
			in.get(ch);
			if(in.eof())break;
			findCode(root , ch , q);
			while(!q.empty()){
				n = q.front();
				q.pop_front();
				out<<n;
			}
		}
		in.close();
		out.close();
		return true;
	}
	bool findCode(BinTreeNode<word> *root , char &w , list<int> &q){
		if(root == NULL)return false;
		if(root->value.ch == w)return true;
		q.push_back(0);
		if(findCode(root->leftChild , w , q))return true;
		q.pop_back();
		q.push_back(1);
		if(findCode(root->rightChild , w , q))return true;
		q.pop_back();
		return false;
	}

	bool decode(char *CodeFile , char *TextFile){
		if(root == NULL)readTree();
		ifstream in(CodeFile);
		ofstream out(TextFile);
		if(!in || !out)return false;
		BinTreeNode<word> *temp = root;
		char ch;
		for(; ;){
			while(temp->leftChild != NULL && temp->rightChild != NULL){
				in.get(ch);
				if(ch == '0')temp = temp->leftChild;
				if(ch == '1')temp = temp->rightChild;
			}
			if(in.eof())break;
			out<<temp->value.ch;
			temp = root;
		}
		in.close();
		out.close();
		return true;
	}

	void TreePainting(){
		list<BinTreeNode<word>*> q;
		list<int> num;
		BinTreeNode<word> *temp = root;
		int level = size * 2;
		q.push_back(temp);
		num.push_back(1);
		for(int i = 0 , j = 0 , k = 0; !q.empty() ;){
			for(i = 0 ; i < level ; i++)
				cout<<" ";
			k = num.front();
			num.pop_front();
			for(; k > 0 ; k--){
				temp = q.front();
				q.pop_front();
				cout<<temp->value<<" ";
				if(temp->leftChild != NULL){q.push_back(temp->leftChild);j++;}
				if(temp->leftChild != NULL){q.push_back(temp->rightChild);j++;}
			}
			num.push_back(j);j = 0;
			cout<<endl;
			level--;
		}
	}
	protected:
		int size;
};

#endif