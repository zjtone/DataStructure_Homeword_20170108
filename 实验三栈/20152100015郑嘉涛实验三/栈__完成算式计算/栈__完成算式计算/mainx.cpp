#include<iostream>
#include"stack.h"
#include"head.h"
using namespace std;
int main(){
	char src[80];
	char resSrc[160];
	int result;
	cout<<"当第一个符号和第二个符号为0时退出。"<<endl;
	while(1){
		cout<<"请输入表达式："<<endl;
		cin>>src;
		if(src[0] == '0' && src[1] == '0')break;
		midToLast(src , resSrc);
		result = morecalculator(resSrc);
		cout<<"得到的后缀表达式为："<<endl;
		cout<<resSrc<<endl;
		cout<<"计算得到的结果为："<<result<<endl;
	}
	system("pause");
	return 0;
}