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

int main(){
    LinkList L,p;
    int m = 20;
    int n;
    int a[40];
    int xu;
    cin >> n;
    for (int i = 1; i <= n; i++ ){
        cin >> a[i];
    }
    
    
    InitList(L,n,a);
    
    p = L;
    int i = 1;
    while(n){
        if(i == m-1){
            Delete(p, xu, m);
            cout<<xu<<"      ";
            n--;
            i = 0;
            //p = p->next;
                                        }
        else{
            p = p->next;
            i++;
            
            
        }
        
    }
    system("pause");

}