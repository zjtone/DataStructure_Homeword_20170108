#include"List.h"

template<class T>
List<T>::List(T &data){
	head = new LinkNode<T>(data);
}

template<class T>
List<T>::List(T &data , LinkNode<T> *next):{
	head = new LinkNode<T>(data , next);
}

template<class T>
bool List<T>::insert(int i , T &link){
	if(head == NULL){
		head = new LinkNode<T>(link);
		return true;
	}
	if(i < 1)return false;
	if(i == 1){
		head = new LinkNode<T>(link , head);
		return true;
	}
	int k ;
	LinkNode<T> *temp = head;
	if(temp != NULL){
		for(k = 2 ; temp->next != NULL && i != k; k++){
			temp = temp->next;
		}
	}else {
		head = new LinkNode<T>(link , head);
		return true;
	}
	temp->next = new LinkNode<T>(link , temp->next);
	return true;
}

template<class T>
bool List<T>::del(int i){
	if(head == NULL)return false;
	if(i < 1)return false;
	LinkNode<T> *temp = head;
	if(i == 1){
		head = head->next;
//		delete temp;
		return true;
	}
	for(int k = 2 ; temp != NULL && i > k ;k++){
		temp = temp->next;
	}
	if(temp == NULL || temp->next == NULL)return false;
	LinkNode<T> *temp2 = temp->next;
	temp->next = temp->next ->next;
	return true;
}

template<class T>
bool List<T>::writeToFile(){
	fstream os("C:\\student.txt",ios::out);
	if(!os){
		os.open("C:\\student.txt",ios::out);
		if(!os)
			return false;
	}
	LinkNode<T> *temp = head;
	for(;temp != NULL;){
		os<<temp->data;
		temp = temp->next;
	}
	os.close();
	return true;
}

template<class T>
bool List<T>::readFromFile(){
	ifstream is("C:\\student.txt");
	if(!is)return false;
	LinkNode<T> *temp ;
	for(; !is.eof() ; ){
		T data;
		is>>data;
		temp = new LinkNode<T>(data , temp);
	}
	head = temp;
	is.close();
	return true;
}

template<class T>
bool List<T>::isEmpty(){
	if(head == NULL)return true;
	else return false;
}

template<class T>
void List<T>::display(){
	LinkNode<T> *temp = head;
	while(temp != NULL){
		temp->display();
		temp = temp->next;
	}
}

template<class T>
int List<T>::getLength(){
	if(head == NULL)return 0;
	LinkNode<T> *temp = head;
	int i = 0;
	for(;temp != NULL; i++){
		temp = temp->next;
	}
	return i;
}