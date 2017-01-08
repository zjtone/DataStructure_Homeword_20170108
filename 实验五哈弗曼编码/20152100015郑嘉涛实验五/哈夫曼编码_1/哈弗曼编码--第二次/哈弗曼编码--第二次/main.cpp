#include"hfmTree.h"
int main(){
	hfmTree *hfm = new hfmTree();
	for(;;){
		cout<<"哈弗曼编码实验："<<endl;
		cout<<"I ----------初始化(Initialization)"<<endl;
		cout<<"E ----------编码(Encoding)"<<endl;
		cout<<"D ----------译码(Decoding)"<<endl;
		cout<<"输入字母选择功能，输入Q退出: ";
		char c;
		cin>>c;
		if(c)system("cls");
		if(c == 'I' || c == 'i'){
			int n;
			cout<<"请输入字符集的大小： ";cin>>n;
			char *word = new char[n+1];
			int *value = new int[n];
			cout<<"请输入"<<n<<"个字符以及字符的权重：\n";
			char ch;
			for(int i = 0 ; i < n ; i++){
				cin.sync();
				cout<<"请输入字符：";
				cin.get(ch);word[i] = ch;
				cout<<"请输入权重：";cin>>value[i];
				cout<<endl;
			}
			word[n] = '\0';
			hfm->create(word , value , n);
			cout<<"建立哈弗曼树成功！"<<endl;
			cout<<"请等待......"<<endl;
			hfm->writeToFile();
			cout<<"写入文件成功！"<<endl;
			hfm->display();
		}
		if(c == 'E' || c == 'e'){
			hfm->encoding();
			hfm->codeFile();
			cout<<"编码成功！请选择其他功能或打开文件查看！"<<endl;
		}
		if(c == 'D' || c == 'd'){
			hfm->encoding();
			hfm->decodeFile();
			cout<<"译码成功！请选择其他功能或者打开文件查看！"<<endl;
		}
		if(c == 'Q' || c == 'q')exit(0);
	}
	system("pause");
	return 0;
}