#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

#include <iostream>
#include <malloc.h>
#include <stdio.h>

using namespace std;

char OP[] = {'+','-','*','/','(',')','#'};
int pre[7][7] = {{1,1,2,2,2,1,1},{1,1,2,2,2,1,1},{1,1,1,1,2,1,1},{1,1,1,1,2,1,1},{2,2,2,2,2,3,0},{1,1,1,1,0,1,1},{2,2,2,2,2,0,3}};


int cha2num(char a){
	return (a-'0');
}


int Operate(char a,char theta,char b){
	switch(theta){
		case '+':return ((a-'0') + (b-'0'));
		case '-':return ((a-'0') - (b-'0'));
		case '*':return ((a-'0') * (b-'0'));
		case '/':return ((a-'0') / (b-'0'));
	}
}

bool In(char c){
	for(int i=0;i<7;i++){
		if(c == OP[i]) return true;
	}
	return false;
}

char Precede(char a,char b){
	int m,n;
	for(int i=0;i<7;i++){
		if(a==OP[i]) m = i;
	}
	for(int i=0;i<7;i++){
		if(b==OP[i]) n = i;
	}
	
	switch(pre[m][n]){
		case 1: return '>';
		case 2: return '<';
		case 3: return '=';
		case 0: return '0';
	}
}


typedef struct{
	char *base;
	char *top;
	int stacksize;
}SqStack;

int InitStack(SqStack &S){
	S.base = (char *)malloc(100 * sizeof(char));
	if(!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = 100;
	return OK;
	
}  //构造空栈


int StackEmpty(SqStack S){
	if(S.top == S.base) return true;
	else {
	return false;
	}
}


int DestroyStack(SqStack &S){
	char *p = S.base;
	char *q;
	while(p - S.base< S.stacksize-1){
		q = p + 1;
		free(p);
		p = q;
	}
	free(p);
	return OK;
}

int Push(SqStack &S,char e){
	if(S.top - S.base>=S.stacksize){
		S.base = (char *)realloc(S.base,(S.stacksize + 10)*sizeof(char));
	
	if(!S.base) exit(OVERFLOW);
	S.stacksize += 10;
    }
    *S.top = e;
	S.top++;
	return OK; 
}

int Pop(SqStack &S,char &e){
	if(S.top == S.base) return ERROR; 
	S.top--;
	e = *(S.top);
	return OK;
} 

char GetTop(SqStack S){
	char e;
	if(S.top == S.base) return ERROR;
	e = *(S.top - 1);
	return e;
}

void EvaluateExpression(){
	SqStack OPTR,OPND;
	InitStack(OPTR);   //OPTR是运算符栈 
	InitStack(OPND);   //OPND是运算数栈 
	cout<<"输入表达式，例如3*(7-2)#:"<<endl;
	Push(OPTR,'#');
	char c = getchar();
    
	while(c!='#' || GetTop(OPTR) != '#'){
        if (!In(c))    //判断c是否是运算符，不是则进OPND栈 
        {
            Push(OPND,c);
            c = getchar();
        }
		else {
			switch(Precede(GetTop(OPTR),c)){
				case '<':  //栈顶元素优先权较低 
					Push(OPTR,c);c = getchar();
                    break;
                case '=':   //脱括号并接受下一字符 
					char x;
					Pop(OPTR,x);
					c = getchar();
					break;
				case '>':  //退栈并将运算结果入栈 
					char theta,a,b;
					Pop(OPTR,theta);
					Pop(OPND,b);
					Pop(OPND,a);
                    Push(OPND, Operate(a, theta, b) + 48);
                    break;
			}
		}
	}
    printf("答案: %d\n", GetTop(OPND)-0-48);//ascii码中数字与字符的转换 
}

int main(){

	EvaluateExpression();
    system("pause");
}
