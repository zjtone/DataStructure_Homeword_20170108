#include"LinkNode.h"
#include"Student.h"
#include"List.h"
void searchStudent(List<Student> *head , char *s){
	//����ר�����ѧ����д�ģ�����ģ����Ҫʹ��
	if(head == NULL)return ;
	LinkNode<Student> *temp = head->getLinkNode();
	bool flag = false;
	for( ; temp != NULL ; ){
		if(strcmp(temp->data.getId() , s) == 0){
			temp->data.display();
			flag = true;
		}
		if(flag){
			cout<<"�ɹ��ҵ���"<<endl;
			break;
		}
		temp = temp->next;
	}
	if(!flag)cout<<"δ�ҵ���ѧ����"<<endl;
}

bool writeStudent(List<Student> *head , char *s){
	ofstream os(s);
	if(!os)return false;
	LinkNode<Student> *temp = head->getLinkNode();
	Student stu;
	for(;temp != NULL ; ){
		stu = temp->getData();
		os<<stu.getId()<<","<<stu.getName()<<","<<stu.getBirth()
			<<","<<stu.getSex()<<","<<stu.getHealth()<<endl;//���ڲ���������ʹ��get����
		temp = temp->next;
	}
	os<<'.';
	os.close();
	return true;
}

bool readStudent(List<Student> *head , char *s){
	ifstream in(s);
	char Id[13];
	char name[16];
	char birth[10];
	int sex;
	int health;
	char ch;
	Student *student;
	List<Student> *temp = head;
	for(int ii = 0 ; !in.eof() ; ii++){
		in.get(ch);
		for(; ch == '\n';){
			in.get(ch);
		}
		if(ch == '.')break;
		for(int i = 0 ; ch != ',' && i < 12; i++){
			Id[i] = ch;
			in.get(ch);
		}
		Id[11] = '\0';
		in.get(ch);
		for(int i = 0 ; ch != ',' && i < 16 ; i++){
			name[i] = ch;
			in.get(ch);
			if(ch == ',')name[i+1] = '\0';
		}
		in.get(ch);
		for(int i = 0 ; ch != ',' && i < 9 ; i++){
			birth[i] = ch;
			in.get(ch);
		}
		birth[8] = '\0';
		in.get(ch);
		sex = ch-48;
		in.get(ch);in.get(ch);
		health = ch-48;
		student = new Student(Id , name , birth , sex , health);
		temp->insert(ii , *student);
	}
	in.close();
	return true;
}
