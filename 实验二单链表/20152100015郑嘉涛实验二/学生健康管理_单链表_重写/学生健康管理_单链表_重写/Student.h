#ifndef _STUDENT_H
#define _STUDENT_H
#include<fstream>
using namespace std;
//2016-10-27 ** 写一个可不断重复使用的student类，这样下次可以直接使用，而且这个类可以不断优化
class Student{
private:
	char Id[13];
	char name[16];
	char birth[10];
	int sex;
	int health;
public:
	//构造函数
	Student(char *Id = NULL , char *name = NULL , char *birth = NULL , int sex = 0 , int health = 0);
	Student(Student &t);
	~Student();
	//输出student对象
	void display();
	//重载输入、输出函数
	friend istream& operator >> (istream &is , Student &t);
	friend ostream& operator << (ostream &os , Student &t);
	//写入文件，和从文件读取，希望能够使用传入的地址来进行读取写入
	bool writeToFile(char *address = "C:\\student.txt");
	bool readFromFile(char *address = "C:\\student.txt");
	//重载 文件读取写入
	friend ifstream& operator >> (ifstream &ifs , Student &t);
	friend ofstream& operator << (ofstream &ofs , Student &t);
	//重载 ==
	friend bool operator == (Student &t1 , Student &t2);
	//这个类的set函数和get函数
	bool setId(char *id);
	bool setName(char *name);
	bool setBirth(char *birth);
	bool setSex(int sex);
	bool setHealth(int health);
	char* getId();
	char* getName();
	char* getBirth();
	int getSex();
	int getHealth();
	friend Student* newStudent();
};

#endif