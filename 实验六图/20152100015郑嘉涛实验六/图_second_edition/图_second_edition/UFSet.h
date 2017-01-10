#ifndef _UFSET_H
#define _UFSET_H
template<class T>
struct UFSNode{
	T data;
	int root;
	UFSNode<T>(){
		root = -1;
	}
	UFSNode<T>(T data , int root = -1){
		this->data = data;
		this->root = root;
	}
};

template<class T>
class UFSet{
public:
	UFSet<T>(int sz = 40){
		capacity = sz;
		size = 0;
		set = new UFSNode<T>[capacity];
	}
	UFSet<T>(UFSNode<T> *s , int n){
		size = n;
		set = new UFSNode<T>[size];
		for(int i = 0 ; i < size ; i++)
			set[i] = s[i];
	}
	UFSet<T>(T *t , int n){
		size = n;
		set = new UFSNode<T>[size];
		for(int i = 0 ; i < size ; i++)
			set[i] = *new UFSNode<T>(t[i]);
	}
	~UFSet<T>(){delete []set;}
	void Union(int u , int v){
		if(u > size || v > size)return;
		for(; set[v].root != -1; v = set[v].root);
		set[v].root = u;
	}
	int Find(int u){
		if(u > size)return -1;
		for(; set[u].root != -1; u = set[u].root);
		return u;
	}
	bool Insert(T &t){
		if(IsFull())return false;
		set[size++] = new UFSNode<T>(t);
		return true;
	}
	//没有实现删除标记，删除有点麻烦，暂时略过
	bool IsFull()const{
		return (size == capacity);
	}
	bool IsEmpty()const{
		return (size == 0);
	}
protected:
	UFSNode<T> *set;
	int size;
	int capacity;
};
#endif