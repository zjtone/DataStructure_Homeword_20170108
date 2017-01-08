/*ʵ��ѧ�������������ļ�����������
���½������롢ɾ�������ļ���ȡ��д���ļ��Ͳ�ѯ����Ļ����ȹ��ܣ���
��������ѧ������Ϣ��ѧ�š��������������ڡ��Ա�����״���ȡ�*/

#include<iostream>
#include<fstream>
using namespace std;
struct Student{
	//������Ҫ����������
	char id[12];
	char name[20];
	char birth[9];
	char health;// 1������  2��������  3����һ��  4�����

	Student(){}
	Student(char _id[] , char _name[] , char _birth[] , char _health){
		for(int i = 0 ; i < 12 ; i++)id[i] = _id[i];
		for(int i = 0 ; i < 20 ; i++)name[i] = _name[i];
		for(int i = 0 ; i < 9 ; i++)birth[i] = _birth[i];
		health = _health;
	}
};
class stuList{
	Student *student;
	int maxSize;
	int last;

public:
	//������ʵ�����ʵ�ֺ���
	void create();
	void insert();
	void del();
	void writeToFile();
	void readFromFile();
	void searchById();
	void printStu();

	stuList(){
		maxSize = 100;
		last = -1;
		student = NULL;
	}
};
//����
void stuList::create(){
	student = new Student[maxSize];
	cout<<"�½��ɹ���"<<endl;
}
//����
void stuList::insert(){
	if(student == NULL){
		cout<<"˳�����δ������"<<endl<<endl;
		return ;
	}
	if(last == maxSize ){
		cout<<"˳����ѵ�����󳤶ȣ�"<<endl<<endl;
		return ;
	}
	char id[12];
	char name[20];
	char birth[9];
	char health;
	while(1){
		cin.sync();
		cout<<"������11λ��ѧ�ţ�";
		cin>>id;
		if(sizeof(id) != 12)cout<<"�����ѧ�Ų��Ϸ���"<<endl;
		else break;
	}
	cin.sync();
	cout<<"�������������֣�";
	cin>>name;

	while(1){
		cin.sync();
		cout<<"���������ĳ������ڣ���ʽ��20080801����";
		cin>>birth;
		if(sizeof(birth) != 9)cout<<"����ĳ������ڲ��Ϸ���"<<endl;
		else break;
	}
	while(1){
		cin.sync();
		cout<<"���������Ľ���״����1������  2��������  3����һ��  4������";
		cin>>health;
		if(health < '1' || health > '4')cout<<"�����ֵ���Ϸ���"<<endl;
		else break;
	}
	last++;
	student[last] = Student(id , name ,birth , health);
	cout<<"����ɹ���"<<endl<<endl;
}
//ɾ��
void stuList::del(){
	bool flag = false;
	if(student == NULL){
		cout<<"�ý�����Ϊ�գ�"<<endl;
		return;
	}
	cout<<"������Ҫɾ��ѧ����ѧ�ţ�";
	char delId[12];
	cin>>delId;
	if(sizeof(delId) < 12){
		cout<<"�����ѧ������"<<endl<<endl;
		return;
	}
	for(int i = 0 ; i <= last ; i++){
		if(strcmp(delId , (student+i) -> id) == 0){
			for(int j = i ; j <= last ; j++){
				student[j] = student[j+1];
			}
			last--;
			cout<<"ɾ���ɹ���"<<endl;
			flag = true;
			break;
		}
	}
	if(!flag)cout<<"δ�ҵ���ѧ�ţ�"<<endl;
}

/*
//д���ļ�
void stuList::writeToFile(){
	//ֻ��д��ǡ����λ�ַ����������֣���������
	FILE *out;
	if((out = fopen("D:\\student.txt" , "w+t")) != NULL){
		fwrite(student , sizeof(struct Student) , last+1 , out);
		fclose(out);
		cout<<"д���ļ��ɹ���"<<endl;
	}else {
		cout<<"�ļ��򿪴���"<<endl;
	}
}
*/
//д���ļ�
void stuList::writeToFile(){
	if(last == -1){
		cout<<"û����Ҫд�������"<<endl;
		return;
	}
	fstream out("C:\\Users\\ZZZ\\student.txt" , ios::out);
	if(!out){
		cout<<"���ļ�ʧ�ܣ�"<<endl;
		return;
	}
	for(int i = 0 ; i <= last ; i++){
		out<<(student+i)->id<<","<<(student+i)->name<<","<<(student+i)->birth<<","<<(student+i)->health<<endl;
	}
	out<<".";
	out.close();
	cout<<"д��ɹ�"<<endl;
}


/*
//���ļ���ȡ   δ���
void stuList::readFromFile(){
	FILE *in;
	if((in = fopen("D:\\student.txt" , "r+t")) != NULL){
		create();
		fread(student , sizeof(struct Student) , 1 , in);
		fclose(in);
		cout<<"��ȡ�ɹ���"<<endl;
	}else {
		cout<<"�ļ������ڣ�"<<endl;
	}

}*/

//���ļ���ȡ
void stuList::readFromFile(){
	fstream in("C:\\Users\\ZZZ\\student.txt" , ios::in);
	if(!in){
		cout<<"�ļ������ڣ�"<<endl;
		return;
	}
	if(student == NULL){
		cout<<"˳�����δ������"<<endl<<endl;
		return ;
	}
	char ch;
	while(1){
		if(last == maxSize ){
			cout<<"˳����ѵ�����󳤶ȣ��޷�������ȡ�ļ��е�����!"<<endl<<endl;
			in.close();
			return ;
		}
		char id[12];
		char name[20];
		char birth[9];
		char health;
		in.get(ch);
		if(ch == '.')break;
		last++;
		int i;
		for(i = 0 ; ch != ',' ; i++){
			id[i] = ch;
 			in.get(ch);
		}
		id[11] = '\0';
		in.get(ch);
		for(i = 0 ; ch != ',' ; i++){
			name[i] = ch;
			in.get(ch);
		}
		name[i] = '\0';
		in.get(ch);
		for(i = 0 ; ch != ',' ; i++){
			birth[i] = ch;
			in.get(ch);
		}
		birth[8] = '\0';
		in.get(ch);
		health = ch;
		in.get(ch);
		student[last] = Student(id , name ,birth , health);
	}
	cout<<"��ȡ�ɹ�"<<endl;
	in.close();
}


//��ID����
void stuList::searchById(){
	if(student == NULL){
		cout<<"�ý��������ڣ�"<<endl;
		return;
	}
	char stu[12];
	bool flag = false;
	cout<<"��������Ҫ���ҵ�ѧ����ѧ�ţ�";
	cin>>stu;
	for(int i = 0 ; i <= last ; i++){
		if(strcmp(stu , (student+i) -> id) == 0){
			cout<<"���ҳɹ���"<<endl;
			cout<<"��ѧ����ѧ�š��������������ڡ�����״�����£�"<<endl;
			cout<<(student+i)->id<<"  "<<(student+i)->name<<"  "<<(student+i)->birth;
			switch((student+i)->health){
			case '1':cout<<"  ����"<<endl;break;
			case '2':cout<<"  ����"<<endl;break;
			case '3':cout<<"  һ��"<<endl;break;
			case '4':cout<<"  ��"<<endl;break;
			}
			flag = true;
		}
	}
	if(!flag)cout<<"��ѧ��������!"<<endl;
}
//���ȫ��ѧ����Ϣ
void stuList::printStu(){
	if(student == NULL){
		cout<<"�ý��������ڣ�"<<endl;
		return;
	}
	cout<<"����ѧ����ѧ�š��������������ں�����״�����£�"<<endl;
	for(int i = 0 ; i <= last ; i++){
		cout<<(student+i)->id<<"  "<<(student+i)->name<<"  "<<(student+i)->birth;
			switch((student+i)->health){
			case '1':cout<<"  ����"<<endl;break;
			case '2':cout<<"  ����"<<endl;break;
			case '3':cout<<"  һ��"<<endl;break;
			case '4':cout<<"  ��"<<endl;break;
			}
	}
	cout<<"����ѧ������Ϣ�����ϣ�\n\n"<<endl;
}

void main(){
	stuList list;
	while(1){
		cout<<"1------�½�ѧ��������"<<endl;
		cout<<"2------��ѧ�����������ѧ����Ϣ"<<endl;
		cout<<"3------�ڽ�����ɾ��ѧ����Ϣ"<<endl;
		cout<<"4------���ļ��ж�ȡ��������Ϣ"<<endl;
		cout<<"5------���ļ�д��ѧ����������Ϣ"<<endl;
		cout<<"6------�ڽ������в�ѯѧ����Ϣ����ѧ��ѧ�������в��ң�"<<endl;
		cout<<"7------����Ļ�����ȫ��ѧ����Ϣ"<<endl;
		cout<<"8-----�˳�"<<endl;
		cout<<"�������ѡ����:";
		int NO;
		if(cin>>NO)system("cls");
		if(NO == 1)list.create();
		if(NO == 2)list.insert();
		if(NO == 3)list.del();
		if(NO == 4)list.readFromFile();
		if(NO == 5)list.writeToFile();
		if(NO == 6)list.searchById();
		if(NO == 7)list.printStu();
		if(NO == 8)exit(1);
	}
}