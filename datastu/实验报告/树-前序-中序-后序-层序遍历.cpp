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
typedef char ElemType;

#include <algorithm>
#include <iostream>
#include <malloc.h>
#include <stdio.h>







typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;


typedef struct 
{
    BiTNode *base;
    int front;
    int rear;
}SqQueue;

Status InitQueue(SqQueue &Q){
    Q.base = (BiTNode *)malloc(100 * sizeof(BiTNode));
    //分配失败
    Q.front = Q.rear = 0;
    return OK;
}

Status EnQueue(SqQueue &Q,BiTNode e){
    if((Q.rear + 1) % 100 == Q.front)
        return ERROR;
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % 100;
    return OK;
}

Status DeQueue(SqQueue &Q,BiTNode &e){
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




Status CreateBiTree(BiTree &T)
{
    char e;
    e = getchar();
    if(e == ' ')
        T = NULL;
    else
    {
        T = (BiTNode *)malloc(sizeof(BiTNode));
        if(!T)
            exit(OVERFLOW);
        T->data = e;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    //cout<<*e<<'\n';
    return OK;
}

char *a = "ABC  DE G  F   ";

//Status CreateBiTreeWithChars(BiTree &T)
//{
//    char e;
//    e = *a;
//    a = a + 1;
//    cout<<&a<<endl;
//    if(&a == NULL) return OK;
//	
//	if(e == ' ')
//        T = NULL;
//    else
//    {
//        T = (BiTNode *)malloc(sizeof(BiTNode));
//        if(!T)
//            exit(OVERFLOW);
//        T->data = e;
//        CreateBiTree(T->lchild);
//        CreateBiTree(T->rchild);
//    }
//    //cout<<*e<<'\n';
//    return OK;
//}

Status PrintElem(ElemType e){
    cout << e;
    return OK;
}

Status PreOrderTraverse(BiTree T,Status (*Visit)(ElemType e)){
	if(T){
		if(Visit(T->data)){
			if(PreOrderTraverse(T->lchild,Visit)){
				if(PreOrderTraverse(T->rchild,Visit)) return OK;
			}
		}
	}
	else return OK;
}

Status InOrderTraverse(BiTree T, Status (*Visit)(ElemType e))
{
	if(T){
		if(InOrderTraverse(T->lchild,Visit)){
			if(Visit(T->data)){
				if(InOrderTraverse(T->rchild,Visit)) return OK;
			}
		}
	}
	else return OK;
}

Status PostOrderTraverse(BiTree T, Status (*Visit)(ElemType e))
{
	if(T){
		if(PostOrderTraverse(T->lchild,Visit)){
			if(PostOrderTraverse(T->rchild,Visit)){
				if(Visit(T->data)) return OK;
			}
		}
	}
	else return OK;
}

Status HierarchicalOrderTraverse(BiTree T, Status (*Visit)(ElemType e)){
	SqQueue Q;
	InitQueue(Q);
	BiTNode p;
	
	if(T){
		EnQueue(Q,*T);   //根节点入栈 
		while(!QueueEmpty(Q)){
			DeQueue(Q,p);   //出栈 
			cout<<p.data<<" ";
			if(p.lchild) {
				EnQueue(Q,*(p.lchild)); //左子树入栈 
			}
			if(p.rchild) {
				EnQueue(Q,*(p.rchild)); //右子树入栈 
			}
			

		}
	}
	return OK;
}



int main(){
	BiTree T;
	
	cout<<"前序遍历二叉树(ABC  DE G  F   ):"<<endl;
	
	//a = "ABC  DE G  F   ";
	
	CreateBiTree(T);
	//CreateBiTreeWithChars(T);
	cout<<'\n';
	cout<<"\n前序遍历:"<<endl;
	PreOrderTraverse(T,PrintElem);
	cout<<'\n';
	cout<<"\n中序遍历:"<<endl;
	InOrderTraverse(T,PrintElem);
	cout<<'\n';
	cout<<"\n后序遍历:"<<endl;
	PostOrderTraverse(T,PrintElem);
	cout<<'\n';
	cout<<"\n层序遍历:"<<endl;
	HierarchicalOrderTraverse(T,PrintElem);
}

