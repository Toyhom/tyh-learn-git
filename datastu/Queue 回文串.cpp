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
typedef int Status;

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

char GetTop(SqStack S){
	char e;
	if(S.top == S.base) return ERROR;
	e = *(S.top - 1);
	return e;
}

typedef struct{
	char *base;
	int front;
	int rear;
}SqQueue;




Status InitQueue(SqQueue &Q){
	Q.base = (char *)malloc(100*sizeof(int));
	Q.front = Q.rear = 0;
	return OK;
}

Status EnQueue(SqQueue &Q,char e){
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1)%100;
	return OK;
}

Status DeQueue(SqQueue &Q,char &e){
	e = Q.base[Q.front];
	Q.front = (Q.front+1)%100;
	return OK;
}

Status GetHead(SqQueue &Q,char &e){
	e = Q.base[Q.front];
	return OK;
}


bool huiwen(SqQueue Q,SqStack S){
	char q,s;
	while(!StackEmpty(S)){
		GetHead(Q,q);
		s = GetTop(S);
		if(q!=s) return false;
		else {
			DeQueue(Q,q);
			Pop(S,s);
		}
	}
	return true;
}

bool QueueEmpty(SqQueue &Q){
	if((Q.rear +1)%100 == Q.front) return true;
	else return false;
}

int main(){
	SqQueue Q;
	SqStack S;
	InitQueue(Q);
	InitStack(S);
	
	char a;
	while(a = getchar()){
	   if(a == '@') break;
	   EnQueue(Q,a);
	   Push(S,a);
	}
	cout<<huiwen(Q,S);
}
