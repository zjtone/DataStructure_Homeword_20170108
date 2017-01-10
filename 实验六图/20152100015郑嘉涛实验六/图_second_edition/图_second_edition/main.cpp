#include"Graphmtx.h"
#include"GraphList.h"
#include<iostream>
using namespace std;
bool createMtx(char *address , Graphmtx<char , int> *&graph);
bool createList(char *address , GraphList<char , int> *&graph);
int main(){
	while(true){
		cout<<"��ѡ��ʹ�õ�ͼ�洢�ṹ��"<<endl;
		cout<<"1.... �ڽӾ���"<<endl;
		cout<<"2.... �ڽӱ�"<<endl;
		cout<<"0.... �˳�"<<endl;
		int i;cin>>i;
		if(i)system("cls");
		if(i == 1){
			int j;
			Graphmtx<char , int> *graph = NULL;
			while(true){
				cout<<"ͼ���ڽӾ���洢��"<<endl;
				cout<<"1.... �½�"<<endl;
				cout<<"2.... �����������"<<endl;
				cout<<"3.... �����������"<<endl;
				cout<<"0.... ����"<<endl;
				cin>>j;
				if(j)system("cls");
				if(j == 1){
					cout<<"�½�ͼ��"<<endl;
					char *address = new char[50];
					cout<<"������ͼ���ļ�����λ�ã�";
					cin>>address;
					if(createMtx(address , graph))
						cout<<"�½��ɹ���"<<endl;
					delete address;
				}
				if(j == 2){
					if(graph == NULL){
						cerr<<"ͼ�����ڣ�"<<endl;
						continue;
					}
					list<char> L;
					cout<<"ͼ���������������"<<endl;
					cout<<"�ݹ鷽����"<<endl;
					L = graph->DFS();
					while(!L.empty()){
						cout<<L.front()<<"  ";
						L.pop_front();
					}
					cout<<"\n�ǵݹ鷽����"<<endl;
					L = graph->DFSstack();
					while(!L.empty()){
						cout<<L.front()<<"  ";
						L.pop_front();
					}
					cout<<"\n�ɹ���"<<endl;
				}
				if(j == 3){
					if(graph == NULL){
						cerr<<"ͼ�����ڣ�"<<endl;
						continue;
					}
					list<char> L;
					cout<<"ͼ�Ĺ������������"<<endl;
					L = graph->BFS();
					while(!L.empty()){
						cout<<L.front()<<"  ";
						L.pop_front();
					}
					cout<<"\n�ɹ���"<<endl;
				}
				if(j == 0){
					system("cls");
					break;
				}
			}
		}
		if(i == 2){
			int j;
			GraphList<char , int> *graph = NULL;
			while(true){
				cout<<"ͼ���ڽӱ�洢��"<<endl;
				cout<<"1.... �½�"<<endl;
				cout<<"2.... �����������"<<endl;
				cout<<"3.... �����������"<<endl;
				cout<<"0.... ����"<<endl;
				cin>>j;
				if(j)system("cls");
				if(j == 1){
					cout<<"�½�ͼ���ڽӱ�"<<endl;
					char address[50];
					cout<<"������ͼ�ı��ش洢λ�ã�";
					cin>>address;
					if(createList(address , graph))
						cout<<"�½��ɹ���"<<endl;
					else 
						cout<<"�½�ʧ�ܣ�"<<endl;
				}
				if(j == 2){
					if(graph == NULL){
						cerr<<"ͼ�����ڣ�"<<endl;
						continue;
					}
					list<char> L;
					cout<<"ͼ���������������"<<endl;
					cout<<"�ݹ鷽����"<<endl;
					L = graph->DFS();
					while(!L.empty()){
						cout<<L.front()<<"  ";
						L.pop_front();
					}
					cout<<"\n�ǵݹ鷽����"<<endl;
					L = graph->DFSstack();
					while(!L.empty()){
						cout<<L.front()<<"  ";
						L.pop_front();
					}
					cout<<"\n�ɹ���"<<endl;
				}
				if(j == 3){
					if(graph == NULL){
						cerr<<"ͼ�����ڣ�"<<endl;
						continue;
					}
					list<char> L;
					cout<<"ͼ�Ĺ������������"<<endl;
					L = graph->BFS();
					while(!L.empty()){
						cout<<L.front()<<"  ";
						L.pop_front();
					}
					cout<<"\n�ɹ���"<<endl;
				}
				if(j == 0){
					system("cls");
					break;
				}
			}
		}
		if(i == 0)exit(0);
	}
	system("pause");
	return 0;
}


bool createMtx(char *address , Graphmtx<char , int> *&graph){
	ifstream in(address);
	if(!in){
		cerr<<"û���ļ���"<<endl;return false;
	}
	char c1 , c2 , ch;
	int n = 0 , numver = 0;
	in.get(c1);//�������еĽ��ĸ���
	while(c1 >= '0' && c1 <= '9'){
		n = n*10 + (c1-48);
		in.get(c1);
	}
	numver = n;
	graph = new Graphmtx<char , int>(0 , 65535 , n);
	n = 0;
	in.get(c1);//�������еĻ�������
	while(c1 >= '0' && c1 <= '9'){
		n = n*10 + (c1-48);
		in.get(c1);
	}
	in.get(c1);
	if(c1 == '1')graph->setDirection(true);
	else graph->setDirection(false);
	in.get(c1);
	for(int i = 0 ; i < numver ; i++){
		in.get(c1);
		while(!((c1 >= 'a' && c1 <= 'z' ) 
			|| (c1 >= 'A' && c1 <= 'Z')))
			in.get(c1);
		graph->insertVertices(c1);
	}
	for(int cost = 0 , i = 0 ; !in.eof() && i < n ; i++){
		in.get(c1);
		while(!((c1 >= 'a' && c1 <= 'z' ) 
			|| (c1 >= 'A' && c1 <= 'Z')))
			in.get(c1);
		in.get(c2);
		while(!((c2 >= 'a' && c2 <= 'z' ) 
			|| (c2 >= 'A' && c2 <= 'Z')))
			in.get(c2);
		in.get(ch);
		in.get(ch);
		while(ch >= '0' && ch <= '9'){
			cost = cost*10 + (ch-48);
			in.get(ch);
		}
		graph->insertEdge(c1 , c2 , cost);
		cost = 0;
	}
	return true;
}
bool createList(char *address , GraphList<char , int> *&graph){
	ifstream in;
	in.open(address);
	if(!in)return false;
	char c1 , c2 , ch;
	int v = 0 , e = 0 , cost = 0;
	in.get(ch);
	for(; ch >= '0' && ch <= '9' ;){
		v = v*10 + (ch-48);
		in.get(ch);
	}
	graph = new GraphList<char , int>(0 , 65535 , v);
	in.get(ch);
	for(; ch >= '0' && ch <= '9' ;){
		e = e*10 + (ch-48);
		in.get(ch);
	}
	in.get(ch);
	if(ch == '1')graph->setDirection(true);
	else graph->setDirection(false);
	for(int i = 0 ; i < v ; ){
		in.get(ch);
		if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z'){
			graph->insertVertices(ch);
			i++;
		}
	}
	for(int i = 0 ; i < e && !in.eof() ;){
		in.get(ch);
		while(!(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z'))
			in.get(ch);
		c1 = ch;
		in.get(ch);
		while(!(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z'))
			in.get(ch);
		c2 = ch;
		in.get(ch);
		in.get(ch);
		while(ch >= '0' && ch <= '9'){
			cost = cost * 10 + (ch-48);
			in.get(ch);
		}
		graph->insertEdge(c1 , c2 , cost);
		cost = 0;
		i++;
	}
	return true;
}