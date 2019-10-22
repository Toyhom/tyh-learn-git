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

    if(*e == ' ')
        T = NULL;
    else
    {
        T = (BiTNode *)malloc(sizeof(BiTNode));
        if(!T)
            exit(OVERFLOW);
        T->data = *e;
        e++;
        CreateBiTree(T->lchild,e);
        CreateBiTree(T->rchild,e);
    }
    return OK;
}


Status PrintInt(ElemType e){
    cout << e;
    return OK;
}

Status PreOrderTraverse(BiTree T,Status (*Visit)(ElemType e)){

}

Status InOrderTraverse(BiTree T, Status (*Visit)(ElemType e))
{

}

Status PostOrderTraverse(BiTree T, Status (*Visit)(ElemType e))
{

}