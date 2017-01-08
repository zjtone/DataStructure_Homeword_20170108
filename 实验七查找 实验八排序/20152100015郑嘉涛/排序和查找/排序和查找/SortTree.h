#ifndef _SORTTREE_H
#define _SORTTREE_H
#include"BinTreeNode.h"
class SortTree{
public:
	SortTree(){
		root = NULL;
	}
	SortTree(int *a , int n){
		root = new BinTreeNode(a[0]);
		for(int i = 1 ; i < n ;i++)
			insert(a[i]);
	}
	void insert(int n){
		BinTreeNode *temp = root;
		while(true){
			if(n == temp->value)return;
			if(n > temp->value){
				if(temp->right == NULL){
					temp->right = new BinTreeNode(n);
					break;
				}else
					temp = temp->right;
				continue;
			}
			if(n < temp->value){
				if(temp->left == NULL){
					temp->left = new BinTreeNode(n);
					break;
				}else 
					temp = temp->left;
			}
		}
	}
	bool binSearch(int n){
		BinTreeNode *temp = root;
		for(;;){
			if(n == temp->value)return true;
			if(n > temp->value){
				if(temp->right == NULL){
					temp->right = new BinTreeNode(n);
					return false;
				}
				temp = temp->right;
			}
			else {
				if(temp->left == NULL){
					temp->left = new BinTreeNode(n);
					return false;
				}
				temp = temp->left;
			}
		}
		return false;
	}

	void Mid(){
		Mid(root);
	}
	void Mid(BinTreeNode *r){
		if(r != NULL){
			Mid(r->left);
			cout<<r->value<<" ";
			Mid(r->right);
		}
	}
protected:
	BinTreeNode *root;
};
#endif