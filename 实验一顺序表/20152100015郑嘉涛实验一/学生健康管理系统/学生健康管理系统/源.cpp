/*实现学生健康情况管理的几个操作功能
（新建、插入、删除、从文件读取、写入文件和查询、屏幕输出等功能）。
健康表中学生的信息有学号、姓名、出生日期、性别、身体状况等。*/

#include<iostream>
#include<fstream>
using namespace std;
struct Student{
	//这是需要的数据类型
	char id[12];
	char name[20];
	char birth[9];
	char health;// 1代表健康  2代表良好  3代表一般  4代表差

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
	//以下是实现类的实现函数
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
//创建
void stuList::create(){
	student = new Student[maxSize];
	cout<<"新建成功！"<<endl;
}
//插入
void stuList::insert(){
	if(student == NULL){
		cout<<"顺序表尚未创建！"<<endl<<endl;
		return ;
	}
	if(last == maxSize ){
		cout<<"顺序表已到达最大长度！"<<endl<<endl;
		return ;
	}
	char id[12];
	char name[20];
	char birth[9];
	char health;
	while(1){
		cin.sync();
		cout<<"请输入11位的学号：";
		cin>>id;
		if(sizeof(id) != 12)cout<<"输入的学号不合法！"<<endl;
		else break;
	}
	cin.sync();
	cout<<"请输入您的名字：";
	cin>>name;

	while(1){
		cin.sync();
		cout<<"请输入您的出生日期（格式：20080801）：";
		cin>>birth;
		if(sizeof(birth) != 9)cout<<"输入的出生日期不合法！"<<endl;
		else break;
	}
	while(1){
		cin.sync();
		cout<<"请输入您的健康状况（1代表健康  2代表良好  3代表一般  4代表差）：";
		cin>>health;
		if(health < '1' || health > '4')cout<<"输入的值不合法！"<<endl;
		else break;
	}
	last++;
	student[last] = Student(id , name ,birth , health);
	cout<<"插入成功！"<<endl<<endl;
}
//删除
void stuList::del(){
	bool flag = false;
	if(student == NULL){
		cout<<"该健康表为空！"<<endl;
		return;
	}
	cout<<"请输入要删除学生的学号：";
	char delId[12];
	cin>>delId;
	if(sizeof(delId) < 12){
		cout<<"输入的学号有误！"<<endl<<endl;
		return;
	}
	for(int i = 0 ; i <= last ; i++){
		if(strcmp(delId , (student+i) -> id) == 0){
			for(int j = i ; j <= last ; j++){
				student[j] = student[j+1];
			}
			last--;
			cout<<"删除成功！"<<endl;
			flag = true;
			break;
		}
	}
	if(!flag)cout<<"未找到该学号！"<<endl;
}

/*
//写入文件
void stuList::writeToFile(){
	//只能写入恰好三位字符的中文名字，否则乱码
	FILE *out;
	if((out = fopen("D:\\student.txt" , "w+t")) != NULL){
		fwrite(student , sizeof(struct Student) , last+1 , out);
		fclose(out);
		cout<<"写入文件成功！"<<endl;
	}else {
		cout<<"文件打开错误！"<<endl;
	}
}
*/
//写入文件
void stuList::writeToFile(){
	if(last == -1){
		cout<<"没有需要写入的数据"<<endl;
		return;
	}
	fstream out("C:\\Users\\ZZZ\\student.txt" , ios::out);
	if(!out){
		cout<<"打开文件失败！"<<endl;
		return;
	}
	for(int i = 0 ; i <= last ; i++){
		out<<(student+i)->id<<","<<(student+i)->name<<","<<(student+i)->birth<<","<<(student+i)->health<<endl;
	}
	out<<".";
	out.close();
	cout<<"写入成功"<<endl;
}


/*
//从文件读取   未完成
void stuList::readFromFile(){
	FILE *in;
	if((in = fopen("D:\\student.txt" , "r+t")) != NULL){
		create();
		fread(student , sizeof(struct Student) , 1 , in);
		fclose(in);
		cout<<"读取成功！"<<endl;
	}else {
		cout<<"文件不存在！"<<endl;
	}

}*/

//从文件读取
void stuList::readFromFile(){
	fstream in("C:\\Users\\ZZZ\\student.txt" , ios::in);
	if(!in){
		cout<<"文件不存在！"<<endl;
		return;
	}
	if(student == NULL){
		cout<<"顺序表尚未创建！"<<endl<<endl;
		return ;
	}
	char ch;
	while(1){
		if(last == maxSize ){
			cout<<"顺序表已到达最大长度！无法完整读取文件中的内容!"<<endl<<endl;
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
	cout<<"读取成功"<<endl;
	in.close();
}


//用ID查找
void stuList::searchById(){
	if(student == NULL){
		cout<<"该健康表不存在！"<<endl;
		return;
	}
	char stu[12];
	bool flag = false;
	cout<<"请输入所要查找的学生的学号：";
	cin>>stu;
	for(int i = 0 ; i <= last ; i++){
		if(strcmp(stu , (student+i) -> id) == 0){
			cout<<"查找成功！"<<endl;
			cout<<"该学生的学号、姓名、出生日期、健康状况如下："<<endl;
			cout<<(student+i)->id<<"  "<<(student+i)->name<<"  "<<(student+i)->birth;
			switch((student+i)->health){
			case '1':cout<<"  健康"<<endl;break;
			case '2':cout<<"  良好"<<endl;break;
			case '3':cout<<"  一般"<<endl;break;
			case '4':cout<<"  差"<<endl;break;
			}
			flag = true;
		}
	}
	if(!flag)cout<<"该学生不存在!"<<endl;
}
//输出全部学生信息
void stuList::printStu(){
	if(student == NULL){
		cout<<"该健康表不存在！"<<endl;
		return;
	}
	cout<<"所有学生的学号、姓名、出生日期和身体状况如下："<<endl;
	for(int i = 0 ; i <= last ; i++){
		cout<<(student+i)->id<<"  "<<(student+i)->name<<"  "<<(student+i)->birth;
			switch((student+i)->health){
			case '1':cout<<"  健康"<<endl;break;
			case '2':cout<<"  良好"<<endl;break;
			case '3':cout<<"  一般"<<endl;break;
			case '4':cout<<"  差"<<endl;break;
			}
	}
	cout<<"所有学生的信息输出完毕！\n\n"<<endl;
}

void main(){
	stuList list;
	while(1){
		cout<<"1------新建学生健康表"<<endl;
		cout<<"2------向学生健康表插入学生信息"<<endl;
		cout<<"3------在健康表删除学生信息"<<endl;
		cout<<"4------从文件中读取健康表信息"<<endl;
		cout<<"5------向文件写入学生健康表信息"<<endl;
		cout<<"6------在健康表中查询学生信息（按学生学号来进行查找）"<<endl;
		cout<<"7------在屏幕中输出全部学生信息"<<endl;
		cout<<"8-----退出"<<endl;
		cout<<"输入序号选择功能:";
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