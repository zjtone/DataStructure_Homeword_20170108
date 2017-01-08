#include"Graphics.h"
int main(){
	Graphics *g = new Graphics();
	for(int i = 0;;){
		cout<<"1....新建"<<endl;
		cout<<"2....深度优先搜索"<<endl;
		cout<<"3....广度优先搜索"<<endl;
		cout<<"4....同时进行上述两种搜索"<<endl;
		cout<<"0....退出"<<endl;
		cout<<"请输入节点值进行功能选择：";
		cin>>i;
		if(i)system("cls");
		if(i == 0)exit(0);
		if(i == 1){
			char add[100];
			cout<<"请输入文件所在位置：";
			cin>>add;
			g->readFile(add);
			cout<<"读取成功！"<<endl;
		}
		if(i == 2){
			cout<<"进行深度优先搜索:"<<endl;
			cout<<"结果如下："<<endl;
			g->DFS();
			cout<<"成功！"<<endl;
		}
		if(i == 3){
			cout<<"进行广度优先搜索："<<endl;
			cout<<"结果如下："<<endl;
			g->BFSQueue();
			cout<<"成功！"<<endl;
		}
		if(i == 4){
			cout<<"进行深度优先搜索:"<<endl;
			cout<<"结果如下："<<endl;
			g->DFS();
			cout<<"成功！"<<endl;
			cout<<"进行广度优先搜索："<<endl;
			cout<<"结果如下："<<endl;
			g->BFSQueue();
			cout<<"成功！"<<endl;
		}
	}
	return 0;
}