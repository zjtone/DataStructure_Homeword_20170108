#include<iostream>
#include"stack.h"
#include"head.h"
using namespace std;
int main(){
	char src[80];
	char resSrc[160];
	int result;
	cout<<"����һ�����ź͵ڶ�������Ϊ0ʱ�˳���"<<endl;
	while(1){
		cout<<"��������ʽ��"<<endl;
		cin>>src;
		if(src[0] == '0' && src[1] == '0')break;
		midToLast(src , resSrc);
		result = morecalculator(resSrc);
		cout<<"�õ��ĺ�׺���ʽΪ��"<<endl;
		cout<<resSrc<<endl;
		cout<<"����õ��Ľ��Ϊ��"<<result<<endl;
	}
	system("pause");
	return 0;
}