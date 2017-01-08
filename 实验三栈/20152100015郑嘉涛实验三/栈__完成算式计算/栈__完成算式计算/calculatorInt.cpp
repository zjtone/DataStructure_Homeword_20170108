/*
#include"stack.h"
#include"stack.cpp"
double calculatorInt(char *s){
	Stack<int> num;
	Stack<char> cal;
	int n = 0 , n1 , n2;
	char char2int , c ;
	for(int i = 0 ; s[i] != '\0' ; i++){
		if(s[i] > '9' || s[i] < '0'){
			//数字入栈
			num.Push(n);
			n=0;
			//判断条件后符号入栈
			if(s[i] != ')'){
				cal.getTop(c);
				if(icp(s[i]) > isp(c))cal.Push(s[i]);
				if(icp(s[i]) < isp(c)){
					cal.Pop(c);
					num.Pop(n1);
					num.Pop(n2);
					switch(c){
					case '+':
						n1 += n2;
						num.Push(n1);
						break;
					case '-':
						n1 -= n2;
						num.Push(n1);
						break;
					case '*':
						n1 *= n2;
						num.Push(n1);
						break;
					case '/':
						n1 /= n2;
						num.Push(n1);
						break;
					}
				}
			}
			else {
				cal.Pop(c);
				for(;c != '(';){
					num.Pop(n1);
					num.Pop(n2);
					switch(c){
					case '+':
						n1 += n2;
						num.Push(n1);
						break;
					case '-':
						n1 -= n2;
						num.Push(n1);
						break;
					case '*':
						n1 *= n2;
						num.Push(n1);
						break;
					case '/':
						n1 /= n2;
						num.Push(n1);
						break;
					}
					cal.Pop(c);
				}
			}
		}else{
			n *= 10;
			char2int = s[i];
			n = char2int - 48;
		}
	}
}

int isp(char c){
	switch(c){
	case '(':
		return 1;
		break;
	case '+':
		return 3;
		break;
	case '-':
		return 3;
		break;
	case ')':
		return 6;
		break;
	case '*':
		return 5;
		break;
	case '/':
		return 5;
		break;
	case '%':
		return 5;
		break;
	}
	return 0;
}

int icp(char c){
	switch(c){
	case '(':
		return 6;
		break;
	case '+':
		return 2;
		break;
	case '-':
		return 2;
		break;
	case ')':
		return 1;
		break;
	case '*':
		return 4;
		break;
	case '/':
		return 4;
		break;
	case '%':
		return 4;
		break;
	}
	return 0;
}*/