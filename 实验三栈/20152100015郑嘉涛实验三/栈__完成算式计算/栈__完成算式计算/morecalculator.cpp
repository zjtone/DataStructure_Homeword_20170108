#include<iostream>
#include"stack.h"
#include"stack.cpp"
using namespace std;
int operatorPriority(char ch);
//这里注意，传入的resBack要比src长  
//这个式子是把中缀表达式转成后缀表达式后保存在resBack里
void midToLast(char *src , char *resBack){
	Stack<char> operatorstack;
	operatorstack.Push('#');
	bool flag = true;
	int len = strlen(src) , j = 0;
	for(int i = 0 ; i < len ; i++){
		while(src[i] >= '0' && src[i] <= '9'){
			resBack[j++] = src[i];
			flag = true;
			if(i < len)i++;
			else {
				resBack[j++] = '$';
				break;
			}
		}
		if(flag){resBack[j++] = '$';}
		switch(src[i]){
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
			while((operatorPriority(src[i]) <= 
				operatorPriority(operatorstack.getTop()))
				&& (operatorstack.getTop() != '(')){
					resBack[j++] = operatorstack.getTop();
					operatorstack.Pop();
					if(operatorstack.IsEmpty())break;
			}
			operatorstack.Push(src[i]);
			break;
		case ')':
			while(operatorstack.getTop() != '('){
				resBack[j++] = operatorstack.getTop();
				operatorstack.Pop();
			}
			operatorstack.Pop();
			break;
		case '(':
			operatorstack.Push('(');
			break;
		default:
			break;
		}
		flag = false;
	}
	while(operatorstack.getTop() != '#'){
		resBack[j++] = operatorstack.getTop();
		operatorstack.Pop();
	}
	resBack[j++] = '#';
	resBack[j++] = '\0';
}
int operatorPriority(char ch){
	switch(ch){
	case '#':
		return 0;
		break;
	case ')':
		return 1;
		break;
	case '+':
		return 2;
	case '-':
		return 2;
	case '*':
		return 3;
	case '/':
		return 3;
	case '%':
		return 3;
	case '(':
		return 4;
	}
	return -1;
}

//这是对上面的式子进行计算
int morecalculator(char *res){
	int result = 0;
	Stack<int> operandvalues;
	char *operand = new char[40];
	int temp , left , right;
	int len = strlen(res) , j = -1;
	for(int i = 0 ; i < len ; i++){
		while(true){
			while(res[i] >= '0' && res[i] <= '9'){
				operand[++j] = res[i];
				++i;
			}
			operand[++j] = '\0';
			if(j > 0)operandvalues.Push(atoi(operand));
			j = -1;
			if(res[i] == '$'){++i; continue;}
			else break;
		}
		switch(res[i]){
		case '+':
			right = operandvalues.getTop();
			operandvalues.Pop();
			left = operandvalues.getTop();
			operandvalues.Pop();
			temp = left + right;
			operandvalues.Push(temp);
			break;
		case '-':
			right = operandvalues.getTop();
			operandvalues.Pop();
			left = operandvalues.getTop();
			operandvalues.Pop();
			temp = left - right;
			operandvalues.Push(temp);
			break;
		case '*':
			right = operandvalues.getTop();
			operandvalues.Pop();
			left = operandvalues.getTop();
			operandvalues.Pop();
			temp = left * right;
			operandvalues.Push(temp);
			break;
		case '/':
			right = operandvalues.getTop();
			operandvalues.Pop();
			left = operandvalues.getTop();
			operandvalues.Pop();
			temp = left / right;
			operandvalues.Push(temp);
			break;
		case '%':
			right = operandvalues.getTop();
			operandvalues.Pop();
			left = operandvalues.getTop();
			operandvalues.Pop();
			temp = left % right;
			operandvalues.Push(temp);
			break;
		default:
			result = operandvalues.getTop();
		}
	}
	return result;
}