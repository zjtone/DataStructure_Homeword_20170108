#include"hfmTree.h"
int main(){
	hfmTree *hfm = new hfmTree();
	for(;;){
		cout<<"����������ʵ�飺"<<endl;
		cout<<"I ----------��ʼ��(Initialization)"<<endl;
		cout<<"E ----------����(Encoding)"<<endl;
		cout<<"D ----------����(Decoding)"<<endl;
		cout<<"������ĸѡ���ܣ�����Q�˳�: ";
		char c;
		cin>>c;
		if(c)system("cls");
		if(c == 'I' || c == 'i'){
			int n;
			cout<<"�������ַ����Ĵ�С�� ";cin>>n;
			char *word = new char[n+1];
			int *value = new int[n];
			cout<<"������"<<n<<"���ַ��Լ��ַ���Ȩ�أ�\n";
			char ch;
			for(int i = 0 ; i < n ; i++){
				cin.sync();
				cout<<"�������ַ���";
				cin.get(ch);word[i] = ch;
				cout<<"������Ȩ�أ�";cin>>value[i];
				cout<<endl;
			}
			word[n] = '\0';
			hfm->create(word , value , n);
			cout<<"�������������ɹ���"<<endl;
			cout<<"��ȴ�......"<<endl;
			hfm->writeToFile();
			cout<<"д���ļ��ɹ���"<<endl;
			hfm->display();
		}
		if(c == 'E' || c == 'e'){
			hfm->encoding();
			hfm->codeFile();
			cout<<"����ɹ�����ѡ���������ܻ���ļ��鿴��"<<endl;
		}
		if(c == 'D' || c == 'd'){
			hfm->encoding();
			hfm->decodeFile();
			cout<<"����ɹ�����ѡ���������ܻ��ߴ��ļ��鿴��"<<endl;
		}
		if(c == 'Q' || c == 'q')exit(0);
	}
	system("pause");
	return 0;
}