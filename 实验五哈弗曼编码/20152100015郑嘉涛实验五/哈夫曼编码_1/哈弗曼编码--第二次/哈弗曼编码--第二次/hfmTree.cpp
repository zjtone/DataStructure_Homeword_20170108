#include"hfmTree.h"
bool hfmTree::create(BinTreeNode *&root , char *key , int *value , int n){
	if(value == NULL)return false;
	int m = 2 * n - 1;
	BinTreeNode **t = new BinTreeNode*[m];
	for(int i = 0 ; i < m ; i++){
		if(i < n){
			t[i] = new BinTreeNode(value[i] , key[i]);
		}
		else t[i] = new BinTreeNode();
	}
	for(int i = 0 , j = 0 ; i < m-1 ; i += 2 , j += 1){
		chooseSortTree(t , i , n + j);
		t[i]->parent = t[n + j];
		t[i+1]->parent = t[n + j];
		t[n + j]->value = t[i]->value + t[i+1]->value;
		t[n + j]->leftChild = t[i];
		t[n + j]->rightChild = t[i+1];
	}
	root = t[m-1];
	return true;
}

void chooseSortTree(BinTreeNode **t , int i , int n){
	BinTreeNode *temp;
	for(; i < n ; i++){
		for(int j = i + 1 ; j < n ; j++){
			if(t[i]->value > t[j]->value){
				temp = t[i];
				t[i] = t[j];
				t[j] = temp;
			}
		}
	}
}

void hfmTree::display(BinTreeNode *root , int n){
	if(root != NULL){
		if(n == 0)cout<<"这是按层次输出的方式："<<endl;
		for(int i = 0 ; i < n ; i++)
			cout<<"    ";
		cout<<root->value;
		if(root->key != '0')cout<<" "<<root->key;
		cout<<endl;
		n++;
		display(root->leftChild , n);
		display(root->rightChild , n);
		n--;
	}
}

bool hfmTree::writeToFile(BinTreeNode *root , ofstream &out){
	if(root == NULL){
		out<<"#";
		return true;
	}
	out<<root->value;
	if(root->key != '0')out<<"?"<<root->key;
	out<<"$";
	writeToFile(root->leftChild , out);
	writeToFile(root->rightChild , out);
	return true;
}

bool hfmTree::readFromFile(BinTreeNode *&root , ifstream &in , int &n){
	char ch;
	char key = '0';
	int value = 0;
	in.get(ch);
	if(ch == '#'){
		root = NULL;
		return true;
	}
	for(; ch != '$' ;){
		value = value*10 +(ch-48);
		in.get(ch);
		if(ch == '?'){
			in.get(ch);
			key = ch;
			in.get(ch);
			n++;
		}
	}
	root = new BinTreeNode(value , key);
	readFromFile(root->leftChild , in , n);
	readFromFile(root->rightChild , in , n);
	return true;
}

void hfmTree::encoding(BinTreeNode *root , Code *code , Code &temp , char *word , int &i){
	if(root != NULL){
		if(root->key != '0'){
			word[i] = root->key;
			code[i] = temp;
			i++;
			return ;
		}
		if(root->leftChild != NULL){
			temp.add('0');
			encoding(root->leftChild , code , temp , word , i);
		}
		temp.del();
		if(root->rightChild != NULL){
			temp.add('1');
			encoding(root->rightChild , code , temp , word , i);
		}
		temp.del();
	}
}

int hfmTree::getLocation(Code *code , Code ch , int n){
	for(int i = 0 , len = n ; i < len ; i++){
		if(!strcmp(code[i].getCode() , ch.getCode()))return i;
	}
	return -1;
}

int hfmTree::getLocation(char *word , char ch , int n){
	for(int i = 0 ; i < n ; i++){
		if(word[i] == ch)return i;
	}
	return -1;
}

void hfmTree::write(ofstream &out , Code t){
	char *c = t.getCode();
	int len = t.getN();
	for(int i = 0 ; i < len ; i++){
		out<<c[i];
	}
	out<<endl;
}

void hfmTree::codeFile(ifstream &in , char ch){
	Code temp;
	int i;
	in.get(ch);
	for(; !in.eof() ;){
		if((i = getLocation(ch , n)) != -1){
			temp = code[i];
			write(temp);
		}
		in.get(ch);
	}
}

void hfmTree::decodeFile(ofstream &out , ifstream &in){
	char ch;
	Code temp;
	int i;
	for(; !in.eof();){
		in.get(ch);
		if(ch != '0' && ch != '1'){
			if((i = getLocation(temp)) != -1){
				out<<word[i];
				temp.clear();
			}
		}else {
			temp.add(ch);
		}
	}
}