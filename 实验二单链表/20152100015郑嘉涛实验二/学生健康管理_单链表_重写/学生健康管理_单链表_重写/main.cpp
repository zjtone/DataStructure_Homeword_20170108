#include<iostream>
#include "Student.h"
#include "List.h"
#include "List.cpp"
using namespace std;

int main(){
	List<Student> *head;
	List<Student> *temp;
	for(;;){
		cout<<"1------�½�ѧ��������"<<endl;
		cout<<"2------��ѧ�����������ѧ����Ϣ"<<endl;
		cout<<"3------�ڽ�����ɾ��ѧ����Ϣ"<<endl;
		cout<<"4------���ļ��ж�ȡ��������Ϣ"<<endl;
		cout<<"5------���ļ�д��ѧ����������Ϣ"<<endl;
		cout<<"6------�ڽ������в�ѯѧ����Ϣ"<<endl;
		cout<<"7------����Ļ�����ȫ��ѧ����Ϣ"<<endl;
		cout<<"8-----�˳�"<<endl;
		cout<<"�������ѡ����:";
		int NO;
		cin>>NO;
		if(NO)system("cls");
		if(NO == 1){
			head = new List<Student>();temp = head;
			cout<<"�½��ɹ�"<<endl;
		}
		if(NO == 2){
			Student *student;
			cout<<"������ѧ����ѧ�š����������գ�20151029����"
				"�Ա�1���У�2��Ů��������״����1���ܽ�����2��������3����ͨ��4����������"<<endl;
			student = newStudent();
			cout<<"����������λ�ã���������ֵ����Ĭ�ϲ��ڶ�β�� ";
			cin.sync();
			int i;cin>>i;
			temp->insert(i , *student);
			cout<<"����ɹ���\n\n";
		}
		if(NO == 3){
			Student student;
			cout<<"������ɾ���Ľڵ�ֵ�� ";
			int i;cin>>i;
			temp->del(i);
			cout<<"ɾ���ɹ���"<<endl;
		}
		if(NO == 4){
			cout<<"���ļ��ж�ȡ��ע�⣺�˹�������д���ļ���ʹ��)"<<endl;
			if(readStudent(temp , "C:\\Student.txt"))
				cout<<"��ȡ�ɹ���"<<endl;
			else 
				cout<<"��ȡʧ�ܣ�"<<endl;
		}
		if(NO == 5){
			cout<<"д�뵽�ļ��У�"<<endl;
			bool flag = writeStudent(temp , "C:\\Student.txt");
			if(flag)
				cout<<"д��ɹ���"<<endl;
			else 
				cout<<"д��ʧ�ܣ�"<<endl;
		}
		if(NO == 6){
			char id[13];
			cout<<"������ѧ����ѧ�ţ�"<<endl;
			cin>>id;
			while(strlen(id) != 11){
				cout<<"����������ѧ�ţ�";
				cin>>id;
			}
			searchStudent(head , id);
		}
		if(NO == 7){
			temp->display();
		}
		if(NO == 8)break;
	}
	system("pause");
	return 0;
}