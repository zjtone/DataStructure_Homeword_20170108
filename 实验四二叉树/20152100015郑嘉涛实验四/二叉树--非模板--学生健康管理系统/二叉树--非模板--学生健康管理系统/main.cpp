#include<vector>
#include"BinTree.h"
int main(){
	BinTree *tree = new BinTree();
	for(;;){
		cout<<"��ӭ����ѧ����������ϵͳ��ѧ�����棡"<<endl;
		cout<<"ϵͳ�Ĳ˵����������£�"<<endl;
		cout<<"1------�½�ѧ��������  "<<endl;
		cout<<"2------��ѧ�����������ѧ����Ϣ "<<endl;
		cout<<"3------�ڽ�����ɾ��ѧ����Ϣ "<<endl;
		cout<<"4------���ļ��ж�ȡ��������Ϣ "<<endl;
		cout<<"5------���ļ�д��ѧ����������Ϣ "<<endl;
		cout<<"6------�ڽ������в�ѯѧ����Ϣ����ѧ��ѧ�������в��ң� "<<endl;
		cout<<"7------����Ļ�����ȫ��ѧ����Ϣ "<<endl;
		cout<<"8------�˳� "<<endl;
		cout<<"���������ѡ����:  ";
		int i;
		cin>>i;
		if(i)system("cls");
		if(i == 1){
			int n;
			cout<<"��������Ҫ������ѧ��������";
			cin>>n;
			if(n > 0){
				Student *stu = new Student[n+1];
				cout<<"���½���ѧ�����飺"<<endl;
				cout<<"������ѧ��Ϊʮһλ0ʱ������ա�"<<endl;
				cout<<"������ѧ����ѧ�š����������գ�20151029����"
					"�Ա�1���У�2��Ů��������״����1���ܽ�����2��������3����ͨ��4����������"<<endl;
				int k;
				for(k = 0 ; k < n ; k++){
					stu[k] = *newStudent();
					cout<<"���ǵ� "<<k+1<<" ��ѧ��\n"<<endl;
				}
				if(stu[k].setId("99999999999"))
					tree->createByFront(stu);
				else {
					cout<<"WRONG��"<<endl;
				}
			}
		}
		if(i == 2){//����
			Student *stu;
			stu = newStudent();
			if(tree->insert(stu))
				cout<<"����ɹ���"<<endl;
			else 
				cout<<"����ʧ�ܣ�"<<endl;
		}
		if(i == 3){//ɾ��
			char Id[12];
			cout<<"��������Ҫɾ����ѧ����ѧ�ţ� ";
			cin>>Id;
			if(tree->del(Id)){
				cout<<"ɾ���ɹ���"<<endl;
			}
			else 
				cout<<"ɾ��ʧ�ܣ�"<<endl;
		}
		if(i == 4){//�ļ���ȡ
			cout<<"��ʼ�ļ���ȡ��"<<endl;
			if(tree->readFromFile())
				cout<<"��ȡ�ɹ���"<<endl;
			else 
				cout<<"��ȡʧ�ܣ�"<<endl;
		}
		if(i == 5){//�ļ�д��
			cout<<"��ʼ�ļ�д�룺"<<endl;
			if(tree->writeToFile())
				cout<<"д��ɹ���"<<endl;
			else 
				cout<<"д��ʧ�ܣ�"<<endl;
		}
		if(i == 6){//��ѯ��ѧ��
			char Id[12];
			cout<<"��������Ҫ���ҵ�ѧ����ѧ�ţ�";
			cin>>Id;
			if(tree->search(Id))
				cout<<"���ҳɹ���"<<endl;
			else 
				cout<<"����ʧ�ܣ�"<<endl;
		}
		if(i == 7){//���
			tree->display();
		}
		if(i == 8)return 0;
		if(i >= 9)continue;
	}
	system("pause");
	return 0;
}