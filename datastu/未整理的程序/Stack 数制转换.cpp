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
	int *base;
	int *top;
	int stacksize;
}SqStack;

int InitStack(SqStack &S){
	S.base = (int *)malloc(100 * sizeof(int));
	if(!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = 100;
	return OK;
	
}  //ππ‘Ïø’’ª


bool StackEmpty(SqStack S){
	if(S.top == S.base) return true;
	else {
	return false;
	}
}


int DestroyStack(SqStack &S){
	int *p = S.base;
	int *q;
	while(p - S.base< S.stacksize-1){
		q = p + 1;
		free(p);
		p = q;
	}
	free(p);
	return OK;
}

int Push(SqStack &S,int e){
	if(S.top - S.base>=S.stacksize){
		S.base = (int *)realloc(S.base,(S.stacksize + 10)*sizeof(int));
	
	if(!S.base) exit(OVERFLOW);
	S.stacksize += 10;
    }
    *S.top = e;
	S.top++;
	return OK; 
}

int Pop(SqStack &S,int &e){
	if(S.top == S.base) return ERROR; 
	S.top--;
	e = *(S.top);
	return OK;
} 

int GetTop(SqStack S,int e){
	if(S.top == S.base) return ERROR;
	e = *(S.top - 1);
	return OK;
}


int main(){
	SqStack S;
	InitStack(S);
	int N;
	cin>>N;
	while(N){
	   Push(S,N%8);
	   
	   N = N/8;
	   
	}
	while(!StackEmpty(S)){
		int e=2;
		Pop(S,e);
		printf("%d",e);
	}
}
