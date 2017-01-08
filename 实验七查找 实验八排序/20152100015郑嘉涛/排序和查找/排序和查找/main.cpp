#include<cstdlib>
#include<ctime>
#include"Sort.h"
#include"search.h"
#include"MinHeap.h"
#include"SortTree.h"
void main(){
	srand(time(0));
	int *a;
	int size;
	int chse;
	cout<<"�����������������";
	cin>>size;
	a = new int[size+1];
	while(true){
		cout<<"���½�������(����)�Ͳ��ҵ�ʵ�飺"<<endl;
		cout<<"1....�������򣨵ݹ飩"<<endl;
		cout<<"2....�������򣨷ǵݹ飩"<<endl;
		cout<<"3....��������"<<endl;
		cout<<"4....ѡ������"<<endl;
		cout<<"5....ð������"<<endl;
		cout<<"6....������"<<endl;
		cout<<"7....���ֲ��ң��ݹ飩"<<endl;
		cout<<"8....���ֲ��ң��ǵݹ飩"<<endl;
		cout<<"9....��������������"<<endl;
		cout<<"0....�˳�"<<endl;
		cout<<"��������ѡ���ܣ�";
		cin>>chse;
		if(chse)system("cls");
		if(chse == 1){
			cout<<"��������ĳ����㷨��ʹ�õݹ飺"<<endl;
			cout<<"��ʼ������Ϊ��"<<endl;
			for(int i = 0 ; i < size ; i++)
				cout<<(a[i] = rand()%50)<<"  ";
			cout<<endl;
			cout<<"����������Ϊ��"<<endl;
			qsortUp(a , 0 , size);
			for(int i = 0 ; i < size ; i++)
				cout<<a[i]<<"  ";
			cout<<endl;
		}
		if(chse == 2){
			cout<<"��������ķǵݹ��㷨��"<<endl;
			cout<<"��ʼ������Ϊ��"<<endl;
			for(int i = 0 ; i < size ; i++)
				cout<<(a[i] = rand()%50)<<"  ";
			cout<<endl;
			cout<<"����������Ϊ��"<<endl;
			qosrtStack(a , size);
			for(int i = 0 ; i < size ; i++)
				cout<<a[i]<<"  ";
			cout<<endl;
		}
		if(chse == 3){
			cout<<"��������"<<endl;
			cout<<"��ʼ������Ϊ��"<<endl;
			for(int i = 0 ; i < size ; i++)
				cout<<(a[i] = rand()%50)<<"  ";
			cout<<endl;
			cout<<"����������Ϊ��"<<endl;
			insertSort(a , size);
			for(int i = 0 ; i < size ; i++)
				cout<<a[i]<<"  ";
			cout<<endl;
		}
		if(chse == 4){
			cout<<"ѡ������"<<endl;
			cout<<"��ʼ������Ϊ��"<<endl;
			for(int i = 0 ; i < size ; i++)
				cout<<(a[i] = rand()%50)<<"  ";
			cout<<endl;
			cout<<"����������Ϊ��"<<endl;
			chooseSort(a , size);
			for(int i = 0 ; i < size ; i++)
				cout<<a[i]<<"  ";
			cout<<endl;
		}
		if(chse == 5){
			cout<<"ð������"<<endl;
			cout<<"��ʼ������Ϊ��"<<endl;
			for(int i = 0 ; i < size ; i++)
				cout<<(a[i] = rand()%50)<<"  ";
			cout<<endl;
			cout<<"����������Ϊ��"<<endl;
			bubbleSort(a , size);
			for(int i = 0 ; i < size ; i++)
				cout<<a[i]<<"  ";
			cout<<endl;
		}
		if(chse == 6){
			cout<<"������"<<endl;
			cout<<"��ʼ������Ϊ��"<<endl;
			for(int i = 1 ; i <= size ; i++)
				cout<<(a[i] = rand()%91)<<"  ";
			MinHeap *heap = new MinHeap(a , size);
			heap->HeapSort();
			cout<<endl;
			cout<<"����������Ϊ��"<<endl;
			for(int i = 1 ; i <= size ; i++)
				cout<<a[i]<<"  ";
			cout<<endl;
		}
		if(chse == 7){
			cout<<"���ֲ����������У�";
			for(int i = 0 ; i < size ; i++)
				cout<<a[i]<<"  ";
			cout<<"\n����������Ҫ���ҵ����֣�";
			int find;cin>>find;
			if(binSearchCycle(a , find , 0 , size)){
				cout<<"���ҳɹ����Ҹ�Ԫ��λ�ã�"<<find+1<<endl;
			}else {
				cout<<"���Ҳ��ɹ�!"<<endl;
			}
		}
		if(chse == 8){
			cout<<"���ֲ����������У�";
			for(int i = 0 ; i < size ; i++)
				cout<<a[i]<<"  ";
			cout<<"\n����������Ҫ���ҵ����֣�";
			int find;cin>>find;
			if(binSearch(a , find , size)){
				cout<<"���ҳɹ����Ҹ�Ԫ������λ�ã�"<<find+1<<endl;
			}else {
				cout<<"���Ҳ��ɹ���"<<endl;
			}
		}
		if(chse == 9){
			cout<<"�����������������У�";
			for(int i = 0 ; i < size ; i++)
				cout<<(a[i] = rand()%90)<<"  ";
			cout<<endl;
			SortTree *tree = new SortTree(a , size);
			int find;
			cout<<"����������Ҫ���ҵ�Ԫ�أ�";cin>>find;
			if(tree->binSearch(find))
				cout<<"���ҳɹ���"<<endl;
			else 
				cout<<"���Ҳ��ɹ����Ѿ���Ԫ�ز��������"<<endl;
			cout<<endl;
			delete tree;
		}
		if(chse == 0)exit(0);
	}
	delete a;
	system("pause");
}