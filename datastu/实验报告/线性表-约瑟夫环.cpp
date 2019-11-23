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

typedef struct LNode
{
    int data1;
    int data2;
    struct LNode *next;

} LNode, *LinkList;



int InitList(LinkList &L,int n,int a[]){
    LinkList head = (LinkList)malloc(sizeof(LNode));

    LinkList p = head;
    L = head;


    int i = 1;
    for (; i < n;i++){
        p->data1 = i;
        p->data2 = a[i];
        p->next = (LinkList)malloc(sizeof(LNode));
        p = p->next;
        
    }
    p->data1 = n;
    p->data2 = a[n];
    p->next = head;
}

int Delete(LinkList &p,int &xu,int &mi)
{

    LinkList q;
    
    q = p->next;
    p->next = q->next;
    xu = q->data1;
    mi = q->data2;
    free(q);
    
    return OK;
}


void JosephRing(){
    LinkList L,p;
    int m = 20;
    int n;
    int a[40];
    int xu;
    cout<<"请输入人数(7):" <<endl;
    cin >> n;
    cout<<"请输入这些人的密码(3,1,7,2,4,8,4):" <<endl;
	for (int i = 1; i <= n; i++ ){
        cin >> a[i];
    }
	InitList(L,n,a);
    cout<<"出列顺序为:"<<endl;
    p = L;
    int i = 1;
    while(n){
        if(i == m-1){
            Delete(p, xu, m); //删除的是p->next 
            cout<<xu<<"    ";
            n--;
            i = 0;
        }
        else{
            p = p->next;
            i++;
        }
    }	
}


int main(){

	JosephRing();
    system("pause");

}
