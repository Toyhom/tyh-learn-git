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
	
}  //ππ‘Ïø’’ª


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

char GetTop(SqStack S,char e){
	if(S.top == S.base) return ERROR;
	e = *(S.top - 1);
	return e;
}


int main(){
	SqStack S;
	InitStack(S);
	char e;
	char z;
	while((e = getchar())!='\n'){
		if(e == '(' || e == '[')  Push(S,e); 
		else if(e == ')'){
			if(GetTop(S,z) == '(') Pop(S,z);
			else {cout<<"Flase"; return 0;}
		}
		else if(e == ']'){
			if(GetTop(S,z) == '[') Pop(S,z);
			else {cout<<"Flase"; return 0;}
		}		
	}
	cout<<"True";
	return 0;
}
