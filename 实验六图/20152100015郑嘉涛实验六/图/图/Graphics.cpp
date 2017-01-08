#include"Graphics.h"

void Graphics::readFile(ifstream &in){
	char ch;
	in.get(ch);
	while(ch < '0' || ch > '9')in.get(ch);
	n = ch-48;
	int len;//�������бߵ�����
	in.get(ch);
	while(ch < '0' || ch > '9')in.get(ch);
	len = ch-48;
	in.get(ch);
	while(ch < '0' || ch > '9')in.get(ch);
	if(ch-48 == 0)direction = false;//����ͼ
	else if(ch-48 == 1)direction = true;//����ͼ
	//��ʼ��������ʼ�ռ�
	word = new char[n+1];
	word[n] = '\0';
	start = new GraphNode[n];
	key = new int*[n];
	for(int i = 0 ; i < n ; i++){
		key[i] = new int[n];
		for(int j = 0 ; j < n ; j++)
			key[i][j] = 0;
	}
	in.get(ch);
	//�������н��
	for(int i = 0 ; i < n ; in.get(ch)){
		if(ch >= 'A' && ch <= 'Z'){
			word[i] = ch;
			start[i].key = i;
			i++;
		}
	}
	//��ʼ�����б�
	in.get(ch);
	GraphNode *temp;
	for(int i = 0 , row = 0  , col = 0 ; i < len ; in.get(ch)){
		if(ch >= 'A' && ch <= 'Z'){
			row = getLocation(ch);
			for(in.get(ch) ; ch < 'A' || ch > 'Z' ; in.get(ch));
			col = getLocation(ch);
			key[row][col] = 1;//�ڽӾ���ֵ
			temp = &start[row];
			for( ; temp->next != NULL ; temp = temp->next);
			temp->next = new GraphNode(col);
			//cout<<word[col]<<"  |  ";
			if(!direction){//������ͼ���еĲ���
				key[col][row] = 1;
				temp = &start[col];
				for( ; temp->next != NULL ; temp = temp->next);
				temp->next = new GraphNode(row);
			}
			i++;
		}
	}
	//��������
}
//�����������
void Graphics::DFS(GraphNode *start , bool *visited , int i){
	cout<<word[i]<<"  |  ";
	visited[i] = true;
	GraphNode *temp = &start[i];
	while(temp != NULL){
		if(!visited[i])DFS(start , visited , i);
		i = temp->key;
		temp = temp->next;
	}
	if(!visited[i])DFS(start , visited , i);//�˾�Ϊ������ӣ�����û�У���֪���ǲ������ϴ��󣬵����ҵĽṹ���ܺ����ϵĲ�һ����
}

void Graphics::BFSQueue(GraphNode *start , bool *visited){
	queue<GraphNode> q;
	q.push(start[0]);
	GraphNode *next;
	GraphNode temp;
	for(;!q.empty();){
		temp = q.front();
		q.pop();
		if(!visited[temp.key]){
			cout<<word[temp.key]<<"  |  ";
			visited[temp.key] = true;
		}
		next = &start[temp.key];
		for(next = next->next;next != NULL;){
			q.push(*next);
			next = next->next;
		}
	}
}

int Graphics::getLocation(char ch){
	if(word == NULL)return -1;
	for(int i = 0 ; i < n ; i++){
		if(ch == word[i])return i;
	}
	return -1;
}