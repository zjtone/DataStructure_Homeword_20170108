#include<vector>
#include"BinTree.h"
int main(){
	BinTree *tree = new BinTree();
	for(;;){
		cout<<"欢迎进入学生健康管理系统的学生界面！"<<endl;
		cout<<"系统的菜单功能项如下："<<endl;
		cout<<"1------新建学生健康表  "<<endl;
		cout<<"2------向学生健康表插入学生信息 "<<endl;
		cout<<"3------在健康表删除学生信息 "<<endl;
		cout<<"4------从文件中读取健康表信息 "<<endl;
		cout<<"5------向文件写入学生健康表信息 "<<endl;
		cout<<"6------在健康表中查询学生信息（按学生学号来进行查找） "<<endl;
		cout<<"7------在屏幕中输出全部学生信息 "<<endl;
		cout<<"8------退出 "<<endl;
		cout<<"请输入序号选择功能:  ";
		int i;
		cin>>i;
		if(i)system("cls");
		if(i == 1){
			int n;
			cout<<"请输入你要建立的学生总数：";
			cin>>n;
			if(n > 0){
				Student *stu = new Student[n+1];
				cout<<"以下建立学生数组："<<endl;
				cout<<"当输入学号为十一位0时，代表空。"<<endl;
				cout<<"请输入学生的学号、姓名、生日（20151029）、"
					"性别（1：男，2：女）、健康状况（1、很健康，2、健康，3、普通，4、不健康）"<<endl;
				int k;
				for(k = 0 ; k < n ; k++){
					stu[k] = *newStudent();
					cout<<"这是第 "<<k+1<<" 个学生\n"<<endl;
				}
				if(stu[k].setId("99999999999"))
					tree->createByFront(stu);
				else {
					cout<<"WRONG！"<<endl;
				}
			}
		}
		if(i == 2){//插入
			Student *stu;
			stu = newStudent();
			if(tree->insert(stu))
				cout<<"插入成功！"<<endl;
			else 
				cout<<"插入失败！"<<endl;
		}
		if(i == 3){//删除
			char Id[12];
			cout<<"请输入所要删除的学生的学号： ";
			cin>>Id;
			if(tree->del(Id)){
				cout<<"删除成功！"<<endl;
			}
			else 
				cout<<"删除失败！"<<endl;
		}
		if(i == 4){//文件读取
			cout<<"开始文件读取："<<endl;
			if(tree->readFromFile())
				cout<<"读取成功！"<<endl;
			else 
				cout<<"读取失败！"<<endl;
		}
		if(i == 5){//文件写入
			cout<<"开始文件写入："<<endl;
			if(tree->writeToFile())
				cout<<"写入成功！"<<endl;
			else 
				cout<<"写入失败！"<<endl;
		}
		if(i == 6){//查询，学号
			char Id[12];
			cout<<"请输入所要查找的学生的学号：";
			cin>>Id;
			if(tree->search(Id))
				cout<<"查找成功！"<<endl;
			else 
				cout<<"查找失败！"<<endl;
		}
		if(i == 7){//输出
			tree->display();
		}
		if(i == 8)return 0;
		if(i >= 9)continue;
	}
	system("pause");
	return 0;
}