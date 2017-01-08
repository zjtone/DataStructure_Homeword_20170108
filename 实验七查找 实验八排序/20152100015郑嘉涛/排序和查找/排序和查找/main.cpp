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
	cout<<"请输入排序的容量：";
	cin>>size;
	a = new int[size+1];
	while(true){
		cout<<"以下进行排序(升序)和查找的实验："<<endl;
		cout<<"1....快速排序（递归）"<<endl;
		cout<<"2....快速排序（非递归）"<<endl;
		cout<<"3....插入排序"<<endl;
		cout<<"4....选择排序"<<endl;
		cout<<"5....冒泡排序"<<endl;
		cout<<"6....堆排序"<<endl;
		cout<<"7....二分查找（递归）"<<endl;
		cout<<"8....二分查找（非递归）"<<endl;
		cout<<"9....二叉搜索树查找"<<endl;
		cout<<"0....退出"<<endl;
		cout<<"输入数字选择功能：";
		cin>>chse;
		if(chse)system("cls");
		if(chse == 1){
			cout<<"快速排序的常规算法，使用递归："<<endl;
			cout<<"初始化数组为："<<endl;
			for(int i = 0 ; i < size ; i++)
				cout<<(a[i] = rand()%50)<<"  ";
			cout<<endl;
			cout<<"排序后的数组为："<<endl;
			qsortUp(a , 0 , size);
			for(int i = 0 ; i < size ; i++)
				cout<<a[i]<<"  ";
			cout<<endl;
		}
		if(chse == 2){
			cout<<"快速排序的非递归算法："<<endl;
			cout<<"初始化数组为："<<endl;
			for(int i = 0 ; i < size ; i++)
				cout<<(a[i] = rand()%50)<<"  ";
			cout<<endl;
			cout<<"排序后的数组为："<<endl;
			qosrtStack(a , size);
			for(int i = 0 ; i < size ; i++)
				cout<<a[i]<<"  ";
			cout<<endl;
		}
		if(chse == 3){
			cout<<"插入排序："<<endl;
			cout<<"初始化数组为："<<endl;
			for(int i = 0 ; i < size ; i++)
				cout<<(a[i] = rand()%50)<<"  ";
			cout<<endl;
			cout<<"排序后的数组为："<<endl;
			insertSort(a , size);
			for(int i = 0 ; i < size ; i++)
				cout<<a[i]<<"  ";
			cout<<endl;
		}
		if(chse == 4){
			cout<<"选择排序："<<endl;
			cout<<"初始化数组为："<<endl;
			for(int i = 0 ; i < size ; i++)
				cout<<(a[i] = rand()%50)<<"  ";
			cout<<endl;
			cout<<"排序后的数组为："<<endl;
			chooseSort(a , size);
			for(int i = 0 ; i < size ; i++)
				cout<<a[i]<<"  ";
			cout<<endl;
		}
		if(chse == 5){
			cout<<"冒泡排序："<<endl;
			cout<<"初始化数组为："<<endl;
			for(int i = 0 ; i < size ; i++)
				cout<<(a[i] = rand()%50)<<"  ";
			cout<<endl;
			cout<<"排序后的数组为："<<endl;
			bubbleSort(a , size);
			for(int i = 0 ; i < size ; i++)
				cout<<a[i]<<"  ";
			cout<<endl;
		}
		if(chse == 6){
			cout<<"堆排序："<<endl;
			cout<<"初始化数组为："<<endl;
			for(int i = 1 ; i <= size ; i++)
				cout<<(a[i] = rand()%91)<<"  ";
			MinHeap *heap = new MinHeap(a , size);
			heap->HeapSort();
			cout<<endl;
			cout<<"排序后的数组为："<<endl;
			for(int i = 1 ; i <= size ; i++)
				cout<<a[i]<<"  ";
			cout<<endl;
		}
		if(chse == 7){
			cout<<"二分查找有序序列：";
			for(int i = 0 ; i < size ; i++)
				cout<<a[i]<<"  ";
			cout<<"\n请输入你所要查找的数字：";
			int find;cin>>find;
			if(binSearchCycle(a , find , 0 , size)){
				cout<<"查找成功！且该元素位置："<<find+1<<endl;
			}else {
				cout<<"查找不成功!"<<endl;
			}
		}
		if(chse == 8){
			cout<<"二分查找有序序列：";
			for(int i = 0 ; i < size ; i++)
				cout<<a[i]<<"  ";
			cout<<"\n请输入你所要查找的数字：";
			int find;cin>>find;
			if(binSearch(a , find , size)){
				cout<<"查找成功！且该元素所在位置："<<find+1<<endl;
			}else {
				cout<<"查找不成功！"<<endl;
			}
		}
		if(chse == 9){
			cout<<"二叉搜索树查找序列：";
			for(int i = 0 ; i < size ; i++)
				cout<<(a[i] = rand()%90)<<"  ";
			cout<<endl;
			SortTree *tree = new SortTree(a , size);
			int find;
			cout<<"请输入你所要查找的元素：";cin>>find;
			if(tree->binSearch(find))
				cout<<"查找成功！"<<endl;
			else 
				cout<<"查找不成功！已经将元素插入该树！"<<endl;
			cout<<endl;
			delete tree;
		}
		if(chse == 0)exit(0);
	}
	delete a;
	system("pause");
}