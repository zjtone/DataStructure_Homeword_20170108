#ifndef _WORD_H
#define _WORD_H
#include<iostream>
using namespace std;
struct word{
	char ch;
	int value;
	word(int value = 0){
		ch = '#';
		this->value = value;
	}
	word(char ch , int value){
		this->ch = ch;
		this->value = value;
	}
	bool operator > (word &w){
		return (value > w.value);
	}
	bool operator >= (word &w){
		return (value >= w.value);
	}
	bool operator < (word &w){
		return (value < w.value);
	}
	bool operator <= (word &w){
		return (value <= w.value);
	}
	bool operator == (word &w){
		return (value == w.value);
	}
	word operator = (const word &w){
		ch = w.ch;
		value = w.value;
		return word(ch , value);
	}
	word operator + (word &w){
		return word('#' , value + w.value);
	}
	friend istream &operator >> (istream &in , word &t){
		in>>t.ch>>t.value;
		return in;
	}
	friend ostream &operator << (ostream &out , word &t){
		out<<t.ch<<" "<<t.value;
		return out;
	}
};

#endif