#include<iostream>
#include "Student.h"
#include "List.h"
#include "List.cpp"
using namespace std;

int main(){
	List<Student> *head;
	List<Student> *temp;
	for(;;){
		cout<<"1------新建学生健康表"<<endl;
		cout<<"2------向学生健康表插入学生信息"<<endl;
		cout<<"3------在健康表删除学生信息"<<endl;
		cout<<"4------从文件中读取健康表信息"<<endl;
		cout<<"5------向文件写入学生健康表信息"<<endl;
		cout<<"6------在健康表中查询学生信息"<<endl;
		cout<<"7------在屏幕中输出全部学生信息"<<endl;
		cout<<"8-----退出"<<endl;
		cout<<"输入序号选择功能:";
		int NO;
		cin>>NO;
		if(NO)system("cls");
		if(NO == 1){
			head = new List<Student>();temp = head;
			cout<<"新建成功"<<endl;
		}
		if(NO == 2){
			Student *student;
			cout<<"请输入学生的学号、姓名、生日（20151029）、"
				"性别（1：男，2：女）、健康状况（1、很健康，2、健康，3、普通，4、不健康）"<<endl;
			student = newStudent();
			cout<<"请输入插入的位置：（若输入值过大，默认插在队尾） ";
			cin.sync();
			int i;cin>>i;
			temp->insert(i , *student);
			cout<<"插入成功！\n\n";
		}
		if(NO == 3){
			Student student;
			cout<<"请输入删除的节点值： ";
			int i;cin>>i;
			temp->del(i);
			cout<<"删除成功！"<<endl;
		}
		if(NO == 4){
			cout<<"从文件中读取（注意：此功能在已写入文件后使用)"<<endl;
			if(readStudent(temp , "C:\\Student.txt"))
				cout<<"读取成功！"<<endl;
			else 
				cout<<"读取失败！"<<endl;
		}
		if(NO == 5){
			cout<<"写入到文件中："<<endl;
			bool flag = writeStudent(temp , "C:\\Student.txt");
			if(flag)
				cout<<"写入成功！"<<endl;
			else 
				cout<<"写入失败！"<<endl;
		}
		if(NO == 6){
			char id[13];
			cout<<"请输入学生的学号："<<endl;
			cin>>id;
			while(strlen(id) != 11){
				cout<<"请重新输入学号：";
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