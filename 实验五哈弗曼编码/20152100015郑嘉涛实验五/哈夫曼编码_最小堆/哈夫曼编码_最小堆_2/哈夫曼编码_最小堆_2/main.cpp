#include<iostream>
#include"hfmCode.h"

#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
	hfmCode *code = new hfmCode();
	for(char ch = ' ';;){
		cout<<"i......初始化"<<endl;
		cout<<"e......编码"<<endl;
		cout<<"d......译码"<<endl;
		cout<<"q......退出"<<endl;
		cout<<"请输入选择功能：";
		cin>>ch;
		if(ch == 'q' || ch == 'Q')break;
		else system("cls");
		if(ch == 'i' || ch == 'I'){
			int n;
			cout<<"请输入字符集的大小：";cin>>n;
			word *w;
			if(n > 0)w = new word[n];
			char ch;
			for(int i = 0 ; i < n ; i++){
				cout<<"请输入字符：";cin.sync();
				cin.get(ch);
				w[i].ch = ch;
				cin.sync();
				cout<<"请输入权值：";cin>>w[i].value;
				cout<<endl;
			}
			code->init(w , n);
			cout<<"初始化成功！"<<endl;
			code->display();
			cout<<endl;
		}
		if(ch == 'e' || ch == 'E'){
			char *in = new char[50];
			cout<<"请输入要编码的文件的位置：";cin>>in;
			char *out = new char[50];
			cout<<"请输入编码后的文件保存的位置：";cin>>out;
			if(code->encode(in , out))
				cout<<"编码成功！"<<endl;
			else 
				cout<<"编码失败！"<<endl;
			delete in;
			delete out;
		}
		if(ch == 'd' || ch == 'D'){
			char *in = new char[50];
			cout<<"请输入要译码的文件的位置：";cin>>in;
			char *out = new char[50];
			cout<<"请输入译码后的文件保存的位置：";cin>>out;
			if(code->decode(in , out))
				cout<<"译码成功！"<<endl;
			else 
				cout<<"译码失败！"<<endl;
			delete in;
			delete out;
		}
	}
	system("pause");
	return 0;
}