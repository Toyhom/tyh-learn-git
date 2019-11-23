#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

using namespace std;

typedef int Status;

#include <iostream>
#include <malloc.h>
#include <stdio.h>


typedef struct 
{
    int *base;
    int front;
    int rear;
}SqQueue;

Status InitQueue(SqQueue &Q){
    Q.base = (int *)malloc(100 * sizeof(int));
    //����ʧ��
    Q.front = Q.rear = 0;
    return OK;
}

Status EnQueue(SqQueue &Q,int e){
    if((Q.rear + 1) % 100 == Q.front)
        return ERROR;
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % 100;
    return OK;
}

Status DeQueue(SqQueue &Q,int &e){
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % 100;
    return OK;
}

bool QueueEmpty(SqQueue &Q){
    if(Q.front == Q.rear)
        return true;
    else
    {
        return false;
    }
    
}

void peach(int n,int k,int m){
    //������ ������ n = 5, k = 3, m = 40; 
	//�ֱ�Ϊ�������������������ҵ����� 
	SqQueue X, P;
    InitQueue(X);
    InitQueue(P);
    int px = 0,pc = 0; //���������,Ҫ�ŵ�����
    for (int i = 1; i <= n;i++){
        EnQueue(X, i);
        EnQueue(P, 0);
    }
    cout<<"��:"<<endl;
    while(!QueueEmpty(X)){
        int x, p;
        DeQueue(X, x);
        DeQueue(P, p);
        
        if(pc == k)
            pc = 0;
        pc++;
        px = px + pc;
        
        if(px + p >= m){
            px = px - (m - p);
            p = m;
           
        }
        else
        {
            p = p + px;
            px = 0;
        }

        if(p == m){
            cout << x << " ";
        }
        else
        {
            EnQueue(X, x);
            EnQueue(P, p);
        }
    }
}

int main(){
    int n = 5, k = 3, m = 40; //�����
    peach(n, k ,m);
    system("pause");
}
