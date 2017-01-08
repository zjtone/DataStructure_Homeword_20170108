#include"BinTree.h"
//使用前序遍历建立二叉树  ,sig是代表空的标志
void BinTree::createByFront(BinTreeNode *&root , Student *s , char *sig , int &i){
	if( !strcmp(s[i].getId() , "99999999999" )|| !strcmp(s[i-1].getId() , "99999999999"))return ;
	if(strcmp(s[i].getId() , sig)){
		root = new BinTreeNode(s[i]);
		i++;
		createByFront(root->leftChild , s , sig , i);
		if( !strcmp(s[i].getId() , "99999999999" )|| !strcmp(s[i-1].getId() , "99999999999"))return ;
		i++;
		createByFront(root->rightChild , s , sig , i);
	}else {
		root = NULL;
	}
}

//递归  前序、中序、后序遍历
void BinTree::visitByFrontCycle(BinTreeNode *temp){
	if(temp != NULL){
		cout<<temp->data<<endl;
		visitByFrontCycle(temp->leftChild);
		visitByFrontCycle(temp->rightChild);
	}
}

void BinTree::visitByMiddleCycle(BinTreeNode *temp){
	if(temp != NULL){
		visitByFrontCycle(temp->leftChild);
		cout<<temp->data<<endl;
		visitByFrontCycle(temp->rightChild);
	}
}

void BinTree::visitByLastCycle(BinTreeNode *temp){
	if(temp != NULL){
		visitByFrontCycle(temp->leftChild);
		visitByFrontCycle(temp->rightChild);
		cout<<temp->data<<endl;
	}
}

//非递归    前序、中序、后序遍历
void BinTree::visitByFront(){
	stack<BinTreeNode *> stu;
	BinTreeNode *temp = root;
	stu.push(temp);
	for( ; !stu.empty() ; ){
		temp = stu.top();
		stu.pop();
		if(temp->rightChild != NULL)stu.push(temp->rightChild);
		if(temp->leftChild != NULL)stu.push(temp->leftChild);
		cout<<temp->data<<endl;
	}
}

void BinTree::visitByMiddle(){
	stack<BinTreeNode *> stu;
	BinTreeNode *temp = root;
	for(;;){
		for(;temp != NULL;){
			stu.push(temp = temp->leftChild);
		}
		do{
			temp = stu.top();
			stu.pop();
			cout<<temp->data<<endl;
			if(stu.empty())return;
		}while(temp->rightChild == NULL || temp->rightChild == stu.top());
		stu.push(temp->rightChild);
	}
}

void BinTree::visitByLast(){
	stack<BinTreeNode *> stu;
	BinTreeNode *temp = root;
	for(;;){
		for(;temp != NULL;){
			stu.push(temp = temp->leftChild);
		}
		do{
			temp = stu.top();
			stu.pop();
			cout<<temp->data<<endl;
			if(stu.empty())return;
		}while(temp == stu.top()->rightChild || stu.top()->rightChild == NULL);
		stu.push(temp->rightChild);
	}
}

//求树高
int BinTree::getHeight(BinTreeNode *root){
	if(root != NULL){
		int m = getHeight(root->leftChild);
		int n = getHeight(root->rightChild);
		return (m>=n)?m:n;
	}
	return 0;
}

//求叶子节点数
void BinTree::countLeaf(BinTreeNode *root , int &n){
	if(root != NULL){
		if(root->leftChild == NULL && root->rightChild == NULL){
			n++;
		}else{
			countLeaf(root->leftChild , n);
			countLeaf(root->rightChild , n);
		}
	}
}

void BinTree::count(BinTreeNode *root , int &n){
	if(root != 0){
		n++;
		count(root->leftChild , n);
		count(root->rightChild , n);
	}
}

//输出二叉树
void BinTree::display(BinTreeNode *root , int n){
	if(root != NULL){
		for(int i = 0 ; i < n ; i++)
			cout<<"        ";
		cout<<root->data;
		cout<<endl;
		n++;
		display(root->leftChild , n);
		display(root->rightChild , n);
		n--;
	}
}

bool BinTree::insert(BinTreeNode *root , Student *s){
	if(root == NULL){
		root = new BinTreeNode(*s);
		return true;
	}
	if(!strcmp(root->data.getId() , "00000000000")){
		root = new BinTreeNode(*s);
		return true;
	}
	if(root->leftChild == NULL){
		root->leftChild = new BinTreeNode(*s);
		return true;
	}
	if(root->rightChild == NULL){
		root->rightChild = new BinTreeNode(*s);
		return true;
	}
	bool flag = insert(root->leftChild , s);
	if(flag)return flag;
	bool flag2 = insert(root->rightChild , s);
	if(flag2)return flag2;
	return false;
}

bool BinTree::del(BinTreeNode *&tree , char *s , BinTreeNode *temp){
	if(tree == NULL)return false;
	if(!strcmp(tree->data.getId() , s)){
		if(temp == NULL){
			BinTreeNode *t = tree->leftChild;
			temp = tree->rightChild;
			tree = t;
			for(; t->leftChild != NULL ; t = t->leftChild);
			t->leftChild = temp;
			return true;
		}
		if(tree->leftChild == NULL && tree->rightChild == NULL){
			if(tree == temp->leftChild){
				temp->leftChild = NULL;
				return true;
			}
			if(tree == temp->rightChild){
				temp->rightChild = NULL;
				return true;
			}
		}
		if(tree == temp->leftChild){
			BinTreeNode *t = tree->rightChild;
			tree = tree->leftChild;
			for(; temp->leftChild != NULL ; temp = temp->leftChild);
			temp->leftChild = t;
			return true;
		}
		if(tree == temp->rightChild){
			BinTreeNode *t = tree->leftChild;
			tree = tree->rightChild;
			for(; temp->rightChild != NULL ; temp = temp->rightChild);
			temp->rightChild = t;
			return true;
		}
	}else {
		temp = root;
		if(del(tree->leftChild , s , temp))return true;
		if(del(tree->rightChild , s , temp))return true;
	}
	return false;
}

bool BinTree::readFromFile(BinTreeNode *&root , char *ad){
	ifstream in(ad);
	if(!in)
		return false;
	char Id[13];
	char name[16];
	char birth[10];
	int sex;
	int health;
	char ch;
	Student *student;
	BinTreeNode *temp;
	for(; !in.eof() ;){
		in.get(ch);
		for( ; ch == '\n' ;)in.get(ch);
		if(ch == '.')break;
		for(int i = 0 ; ch != ',' && i < 12; i++){
			Id[i] = ch;
			in.get(ch);
		}
		Id[11] = '\0';
		in.get(ch);
		for(int i = 0 ; ch != ',' && i < 16 ; i++){
			name[i] = ch;
			in.get(ch);
			if(ch == ',')name[i+1] = '\0';
		}
		in.get(ch);
		for(int i = 0 ; ch != ',' && i < 9 ; i++){
			birth[i] = ch;
			in.get(ch);
		}
		birth[8] = '\0';
		in.get(ch);
		sex = ch-48;
		in.get(ch);in.get(ch);
		health = ch-48;
		student = new Student(Id , name , birth , sex , health);
		if(root == NULL)root = temp = new BinTreeNode(*student);
		else if(temp->leftChild == NULL)temp->leftChild = new BinTreeNode(*student);
		else if(temp->rightChild == NULL)temp->rightChild = new BinTreeNode(*student);
		else 
			insert(student);
	}
	return true;
}

bool BinTree::writeToFile(BinTreeNode *root , char *ad){
	ofstream out(ad);
	if(!out)return false;
	stack<BinTreeNode *>s;
	BinTreeNode *temp =root;
	s.push(temp);
	for( ; !s.empty() ; ){
		temp = s.top();
		s.pop();
		out<<temp->data.getId()<<","<<temp->data.getName()<<","<<temp->data.getBirth()
			<<","<<temp->data.getSex()<<","<<temp->data.getHealth()<<endl;
		if(temp->leftChild != NULL)s.push(temp->leftChild);
		if(temp->rightChild != NULL)s.push(temp->rightChild);
	}
	out<<".";
	return true;
}

bool BinTree::search(BinTreeNode *root , char *id){
	if(root == NULL)
		return false;
	if(!strcmp(root->data.getId() , id)){
		cout<<root->data<<endl;
		return true;
	}
	bool flag = search(root->leftChild , id);
	if(flag)return flag;
	flag = search(root->rightChild , id);
	return flag;
}