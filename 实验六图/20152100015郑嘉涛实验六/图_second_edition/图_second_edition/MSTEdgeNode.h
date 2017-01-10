#ifndef _MSTEDGENODE_H
#define _MSTEDGENODE_H
template<class E>
struct MSTEdgeNode{
	int tail , head;
	E key;
	MSTEdgeNode<E>():tail(-1),head(-1),key(0){}
	MSTEdgeNode<E>(int head , int tail , E key){
		this->head = head;
		this->tail = tail;
		this->key = key;
	}
	bool operator < (MSTEdgeNode<E> &m){return key < m.key;}
	bool operator <= (MSTEdgeNode<E> &m){return key <= m.key;}
	bool operator > (MSTEdgeNode<E> &m){return key > m.key;}
	bool operator >= (MSTEdgeNode<E> &m){return key >= m.key;}
	bool operator == (MSTEdgeNode<E> &m){return key == m.key;}
};
#endif