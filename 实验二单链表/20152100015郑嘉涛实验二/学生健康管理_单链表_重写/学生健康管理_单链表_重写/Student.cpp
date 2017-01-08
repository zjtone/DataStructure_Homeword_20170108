#include<fstream>
#include<iostream>
#include"Student.h"
using namespace std;
Student::Student(char *Id , char *name , char *birth , int sex , int health){
	if(Id != NULL)
		for(int i = 0 ; i < 12 ; i++ ){
			this->Id[i] = Id[i];
		}
		//	this->Id[11] = '\0';
		if(name != NULL)
			for(int i = 0 ; i < 16 ; i++ ){
				this->name[i] = name[i];
			}
			if(birth != NULL)
				for(int i = 0 ; i < 9 ; i++ ){
					this->birth[i] = birth[i];
				}
	//	this->birth[8] = '\0';
	this->sex = sex;
	this->health = health;
}
Student::Student(Student &t){
	char* id = t.getId();
	char* name = t.getName();
	char* birth = t.getBirth();
	int sex = t.getSex();
	int health = t.getHealth();
	try{
		for(int i = 0 ; i < 12 ; i++)
			this->Id[i] = id[i];
		for(int i = 0 ; i < 16 ; i++)
			this->name[i] = name[i];
		for(int i = 0 ; i < 9 ; i++)
			this->birth[i] = birth[i];
		this->sex = sex;
		this->health = health;
	}catch (char*){
		cerr<<"NULL!"<<endl;
	}
}
Student::~Student(){/*
	delete Id;
	delete name;
	delete birth;*/
}
void Student::display(){
	cout<<"学号："<<Id<<" 姓名："<<name<<" 生日："<<birth<<" 性别：";
	switch(sex){
	case 1:
		cout<<"男";
		break;
	case 2:
		cout<<"女";
		break;
	default :
		cout<<"无效值";
		break;
	}
	switch(health){
	case 1:
		cout<<"  很健康"<<endl;
		break;
	case 2:
		cout<<"  健康"<<endl;
		break;
	case 3:
		cout<<"  普通"<<endl;
		break;
	case 4:
		cout<<"  不健康"<<endl;
		break;
	default:
		cout<<"  正常"<<endl;
		break;
	}
}

//这种方式太麻烦
istream & operator >> (istream &is , Student &t){
	char ch;
	int i;
	cin.sync();
	for(i = 0 ; i < 11 ; i++){
		is.get(ch);
		t.Id[i] = ch;
	}
	t.Id[i] = '\0';
	is.get(ch);
	for(;ch == ' ';)is.get(ch);
	for(i = 0 ; i < 15 ; i++){
		t.name[i] = ch;
		is.get(ch);
		if(ch >= '0' && ch <= '9' || ch == ' ')break;
	}
	t.name[i] = '\0';
	for(;ch == ' ';)is.get(ch);
	for(i = 0 ; i < 8 ; i++){
		t.birth[i] = ch;
		is.get(ch);
	}
	t.birth[i] = '\0';
	for(;ch == ' ';)is.get(ch);
	t.sex = ch - 48;
	for(;ch == ' ';)is.get(ch);
	t.health = ch - 48;
	return is;
}
ostream & operator << (ostream &os , Student &t){
	os<<"学号："<<t.getId()<<" 姓名："<<t.getName()<<" 生日："<<t.getBirth()<<" 性别：";
	switch(t.getSex()){
	case 1:
		os<<"男";
		break;
	case 2:
		os<<"女";
		break;
	default :
		os<<"无效值";
		break;
	}
	switch(t.getHealth()){
	case 1:
		os<<"  很健康"<<endl;
		break;
	case 2:
		os<<"  健康"<<endl;
		break;
	case 3:
		os<<"  普通"<<endl;
		break;
	case 4:
		os<<"  不健康"<<endl;
		break;
	default:
		os<<"  正常"<<endl;
		break;
	}
	return os;
}

//第一次这么写，此处很重要
ifstream& operator >> (ifstream &ifs , Student &t){
	if(!ifs)return ifs;
	char ch;
	char cch[16];
	ifs.get(ch);
	while(ch < 48 || ch > 57)ifs.get(ch);
	for(int i = 0 ; ch != ',' && i < 12; i++){
		cch[i] = ch;
		ifs.get(ch);
	}
	t.setId(cch);
	ifs.get(ch);
	for(int i = 0 ; ch != ',' && i < 16 ; i++){
		cch[i] = ch;
		ifs.get(ch);
	}
	t.setName(cch);
	ifs.get(ch);
	for(int i = 0 ; ch != ',' && i < 9 ; i++){
		cch[i] = ch;
		ifs.get(ch);
	}
	t.setBirth(cch);
	ifs.get(ch);
	t.setSex(ch);
	ifs.get(ch);ifs.get(ch);
	t.setHealth(ch);
	return ifs;
}
ofstream& operator << (ofstream &ofs , Student &t){
	if(!ofs)return ofs;
	ofs<<t.getId()<<","<<t.getName()<<","<<t.getBirth()<<","
		<<t.getSex()<<","<<t.getHealth()<<"."<<endl;
	return ofs;
}

bool Student::writeToFile(char *address){
	ofstream out(address);
	if(!out)return false;
	out<<this->getId()<<","<<this->getName()<<","<<this->getBirth()
		<<","<<this->getSex()<<","<<this->getHealth()<<".";//类内部函数不用使用get函数
	return true;
}
bool Student::readFromFile(char *address){
	ifstream in(address);
	if(!in)return false;
	char ch;
	in.get(ch);
	for(int i = 0 ; ch != ',' && i < 12; i++){
		Id[i] = ch;
		in.get(ch);
	}
	in.get(ch);
	for(int i = 0 ; ch != ',' && i < 16 ; i++){
		name[i] = ch;
		in.get(ch);
	}
	in.get(ch);
	for(int i = 0 ; ch != ',' && i < 9 ; i++){
		birth[i] = ch;
		in.get(ch);
	}
	in.get(ch);
	sex = ch;
	in.get(ch);in.get(ch);
	health = ch;
	return true;
}

bool operator == (Student &t1 , Student &t2){
	char *id1 = t1.getId();
	char *id2 = t2.getId();
	int i;
	for(i = 0 ; i < 12 ; i++){
		if(id1[i] != id2[i])break;
	}
	if(i == 11)return true;
	else return false;
}
//实现set方法
bool Student::setId(char *id){
	if(id == NULL)return false;
	if(strlen(id) != 12)return false;
	for(int i = 0 ; i < 12 && id[i] != '\0' ; i++ ){
		this->Id[i] = id[i];
	}
	return true;
}
bool Student::setName(char *name){
	if(name == NULL)return false;
	for(int i = 0 ; i < 16 ; i++){
		this->name[i] = name[i];
	}
	return true;
}
bool Student::setBirth(char *birth){
	if(birth == NULL)return false;
	if(strlen(birth) != 9)return false;

	return true;
}
bool Student::setSex(int sex){
	if(sex != 1 || sex != 2 )return false;
	this->sex = sex;
	return true;
}
bool Student::setHealth(int health){
	if(health < 0 || health > 5)return false;
	return true;
}
//实现get方法
char* Student::getId(){
	return Id;
}
char* Student::getName(){
	return name;
}
char* Student::getBirth(){
	return birth;
}
int Student::getSex(){
	return sex;
}
int Student::getHealth(){
	return health;
}

Student* newStudent(){
	char id[13];
	char name[16];
	char birth[10];
	int sex ;
	int health;
	cin.sync();
	cout<<"请输入学生的学号：";
	cin>>id;
	while(strlen(id) != 11){
		cout<<"重新输入学号：";cin>>id;
	}
	cout<<"请输入学生的姓名：";
	cin.sync();
	cin>>name;
	cout<<"请输入学生的出生日期：";
	cin>>birth;
	while(strlen(birth) != 8){
		cout<<"重新输入出生日期：";cin>>birth;
	}
	cout<<"请输入学生的性别：";
	cin.sync();
	cin>>sex;
	while(sex != 1 && sex != 2){
		cout<<"请重新输入学生的性别：";cin>>sex;
	}
	cout<<"请输入学生的健康状况：";
	cin.sync();
	cin>>health;
	Student *student = new Student(id , name , birth , sex , health);
	return student;
}