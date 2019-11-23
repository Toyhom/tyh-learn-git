#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#include<stdio.h>
#include<malloc.h>
#include <iostream>

using namespace std;




typedef struct LNode{
	char data;
	struct LNode *next;
	
}LNode,*LinkList;

int size = 26;

int InitList(LinkList &L){
	
	LinkList head = (LinkList)malloc(sizeof(LNode));
	
	LinkList p = head;
	L = head;
	p->next=(LinkList)malloc(sizeof(LNode));
	p = p->next;
	
	int i=1;
	for(i=1;i<26;i++)
	{
	p->data=i+'a'-1;
	p->next=(LinkList)malloc(sizeof(LNode));
	p=p->next;
	}
	
	p->data=i+'a'-1;
	p->next=NULL;
	
	return OK;
	
}

int Insert(LinkList &L, int i,char e){
	LinkList p,s;
	p = L;
	int j = 0;
	while(p&&j<i-1) {p = p->next;j++;}
	if(!p||j>i-1) return ERROR;
	s = (LinkList)malloc(sizeof(LNode));
	s->data = e; s->next=p->next;
	p->next = s;
	size++;
	return OK;
	}
	
int Get(LinkList L, int i,char &e){
	LinkList p;
	p = L->next;int j=1;
	while(p&&j<i){
		p = p->next;j++;
		
	}
	if(!p||j>i) return ERROR;
	e = p->data;
	return OK;
}

int Delete(LinkList &L, int i,char &e){
	LinkList p;
	p = L;
	LinkList q;
	int j = 0;
	while(p->next&&j<i-1){
		p = p->next;j++;
		
	}
	if(!(p->next)||j>i-1) return ERROR;
	q = p->next; p->next = q->next;
	e = q->data; free(q);
	size--;
	return OK;
	
}

int main(){
	
	LinkList L;
	
	InitList(L);
	
	//输出全部字母 
	for(int i=1;i<=size;i++){
		char e;
		Get(L,i,e);
		printf("%d:%c ",i,e);
	}
	while(1)
	{
		
		
	printf("输入数字1并输入序号使用删除功能，\n输入数字2并输入序号和字母使用插入功能,\n输入3退出\n");
	int se;
	cin>>se;
	
	if(se == 1) {
		int xu;
		char e;
		cin>>xu;
		Delete(L,xu,e);
		for(int i=1;i<=size;i++){
		char e;
		Get(L,i,e);
		printf("%d:%c ",i,e);
					}
	}
	else if(se == 2){
		int xu;
		char e;
		cin>>xu>>e;
		Insert(L,xu,e);
		for(int i=1;i<=size;i++){
		char e;
		Get(L,i,e);
		printf("%d:%c ",i,e);
			}		
	}
	else if(se == 3){
		break;
	}
	}
	
}

