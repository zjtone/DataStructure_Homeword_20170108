#ifndef _LIST_H
#define _LIST_H
#include<iostream>
#include<fstream>
#include "LinkNode.h"
#include "Student.h"
using namespace std;
template <class T>
class List{
public:
	List(){head = NULL;}
	List(T &data);
	List(T &data , LinkNode<T> *next);
	bool insert(int i , T &link);
	bool del(int i);
	bool writeToFile();
	bool readFromFile();
	bool isEmpty();
	void display();
	int getLength();
	LinkNode<T>* getHead(){
		return head;
	}
	T getData(){
		return head->getData();
	}
	LinkNode<T> *getLinkNode(){
		return head;
	}
private:
	LinkNode<T> *head;
};

void searchStudent(List<Student> *head , char *s);
bool writeStudent(List<Student> *head , char *s);
bool readStudent(List<Student> *head , char *s);
#endif