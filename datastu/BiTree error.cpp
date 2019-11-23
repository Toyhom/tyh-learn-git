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

Status CreateBiTree(BiTree &T,char *e)
{
    e = e++;
    if(*e == ' ')
        T = NULL;
    else
    {
        T = (BiTNode *)malloc(sizeof(BiTNode));
        if(!T)
            exit(OVERFLOW);
        T->data = *e;
        CreateBiTree(T->lchild,e);
        CreateBiTree(T->rchild,e);
    }
    //cout<<*e<<'\n';
    return OK;
}

/*Status CreateBiTree(BiTree &T)
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
}*/


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
int main(){
	BiTree T;
	//CreateBiTree(T);
    CreateBiTree(T, "123");
    cout<<'\n';
	PreOrderTraverse(T,PrintElem);
	cout<<'\n';
	InOrderTraverse(T,PrintElem);
	cout<<'\n';
	PostOrderTraverse(T,PrintElem);
	cout<<'\n';

}
