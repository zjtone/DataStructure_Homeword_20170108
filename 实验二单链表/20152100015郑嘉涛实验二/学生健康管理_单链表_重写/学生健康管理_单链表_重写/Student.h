#ifndef _STUDENT_H
#define _STUDENT_H
#include<fstream>
using namespace std;
//2016-10-27 ** дһ���ɲ����ظ�ʹ�õ�student�࣬�����´ο���ֱ��ʹ�ã������������Բ����Ż�
class Student{
private:
	char Id[13];
	char name[16];
	char birth[10];
	int sex;
	int health;
public:
	//���캯��
	Student(char *Id = NULL , char *name = NULL , char *birth = NULL , int sex = 0 , int health = 0);
	Student(Student &t);
	~Student();
	//���student����
	void display();
	//�������롢�������
	friend istream& operator >> (istream &is , Student &t);
	friend ostream& operator << (ostream &os , Student &t);
	//д���ļ����ʹ��ļ���ȡ��ϣ���ܹ�ʹ�ô���ĵ�ַ�����ж�ȡд��
	bool writeToFile(char *address = "C:\\student.txt");
	bool readFromFile(char *address = "C:\\student.txt");
	//���� �ļ���ȡд��
	friend ifstream& operator >> (ifstream &ifs , Student &t);
	friend ofstream& operator << (ofstream &ofs , Student &t);
	//���� ==
	friend bool operator == (Student &t1 , Student &t2);
	//������set������get����
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