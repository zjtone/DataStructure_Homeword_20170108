#include"Graphics.h"
int main(){
	Graphics *g = new Graphics();
	for(int i = 0;;){
		cout<<"1....�½�"<<endl;
		cout<<"2....�����������"<<endl;
		cout<<"3....�����������"<<endl;
		cout<<"4....ͬʱ����������������"<<endl;
		cout<<"0....�˳�"<<endl;
		cout<<"������ڵ�ֵ���й���ѡ��";
		cin>>i;
		if(i)system("cls");
		if(i == 0)exit(0);
		if(i == 1){
			char add[100];
			cout<<"�������ļ�����λ�ã�";
			cin>>add;
			g->readFile(add);
			cout<<"��ȡ�ɹ���"<<endl;
		}
		if(i == 2){
			cout<<"���������������:"<<endl;
			cout<<"������£�"<<endl;
			g->DFS();
			cout<<"�ɹ���"<<endl;
		}
		if(i == 3){
			cout<<"���й������������"<<endl;
			cout<<"������£�"<<endl;
			g->BFSQueue();
			cout<<"�ɹ���"<<endl;
		}
		if(i == 4){
			cout<<"���������������:"<<endl;
			cout<<"������£�"<<endl;
			g->DFS();
			cout<<"�ɹ���"<<endl;
			cout<<"���й������������"<<endl;
			cout<<"������£�"<<endl;
			g->BFSQueue();
			cout<<"�ɹ���"<<endl;
		}
	}
	return 0;
}