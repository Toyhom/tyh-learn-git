#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

using namespace std;


#include <algorithm>
#include <iostream>
#include <malloc.h>
#include <stdio.h>

typedef struct BiTNode{
	int data;
	struct BiTNode *lchild,*rchild;
	
}BiTNode,* BiTree;

/*void CreateBiTree(BiTree &T){
	BiTree p = T;
	T = (BiTNode *)malloc(sizeof(BiTNode));
	T->data = 45;
	T->lchild = (BiTNode *)malloc(sizeof(BiTNode));
	T->lchild->data = 12;
	T->rchild = (BiTNode *)malloc(sizeof(BiTNode));
	T->rchild->data = 53;
	T->lchild->lchild = (BiTNode *)malloc(sizeof(BiTNode));
	T->lchild->lchild->data = 3
	T->lchild->rchild = (BiTNode *)malloc(sizeof(BiTNode));
	T->lchild->rchild->data = 37
	T = (BiTNode *)malloc(sizeof(BiTNode));
	T->rchild->lchild = NULL;
	T->rchild->rchild->data = 100
	T = (BiTNode *)malloc(sizeof(BiTNode));
	T->lchild->rchild->lchild->data = 24;
	T->lchild->rchild->rchild = NULL;
	T = (BiTNode *)malloc(sizeof(BiTNode));
	T->rchild->rchild->lchild->data = 100;
	T->rchild->rchild->rchild = NULL;
	T = (BiTNode *)malloc(sizeof(BiTNode));
	T->rchild->rchild->lchild->rchild->data = 90;
	T->rchild->rchild->lchild->lchild = NULL;
	T = (BiTNode *)malloc(sizeof(BiTNode));
	T->rchild->rchild->lchild->rchild->lchild->data = 78;
	T->rchild->rchild->lchild->rchild->rchild = NULL;
	
	
}
*/
typedef struct{
	int *elem;
	int length;
}SSTable;



int SearchBST(BiTree T,int key,BiTree f,BiTree &p){
	if(!T){
		p=f;
		return FALSE;
	}
	else if(T->data == key){
		p=T;
		return TRUE;
	}
	else if(key < T->data){
		return SearchBST(T->lchild,key,T,p);
	}
	else return SearchBST(T->rchild,key,T,p);
}

int InsertBST(BiTree &T,int e){
	BiTree p;
	if(!SearchBST(T,e,NULL,p)){
		BiTree s;
		s = (BiTree)malloc(sizeof(BiTNode));
		s->data = e;
		s->lchild = s->rchild = NULL;
		if(!p) T=s;
		else if(e < p->data) p->lchild = s;
		else p->rchild = s;
		return TRUE;
	}
	else return FALSE;
}

int Delete(BiTree &p);

int DeleteBST(BiTree &T,int key){
	if(!T) return FALSE;
	else{
		if(T->data == key) {
		return Delete(T);
		}
		else if(T->data > key) return DeleteBST(T->lchild,key);
		else return DeleteBST(T->rchild,key);
	}
	
}

int Delete(BiTree &p){
	if(!p->rchild){
		BiTree q = p;
		p = p->lchild;
		free(q);
	}
	else if(!p->lchild){
		BiTree q = p;
		p = p->rchild;
		free(q);		
	}
	else {
		BiTree q = p;
		BiTree s = p->lchild;
		while(s->rchild){
			q = s;s = s->rchild;
		}
		p->data = s->data;
		if(q!=p) q->rchild = s->lchild;
		else q->lchild = s->lchild;
		delete s;
	}
	return TRUE;
}

int PrintElem(int e){
    cout << e <<" ";
    return OK;
}

int InOrderTraverse(BiTree T, int (*Visit)(int e))
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


int Search_Seq(SSTable ST,int key){
	ST.elem[0] = key;
	int i;
	for(i = ST.length;ST.elem[i] != key;i--);
	return i;
}


int Search_Bin(SSTable ST,int key,int l,int r){
	int mid = (l+r)/2;
	if(ST.elem[mid] == key) {
	   return mid;	
	}
	else if(ST.elem[mid] > key) Search_Bin(ST,key,l,mid-1);
	else Search_Bin(ST,key,mid+1,r);
}





int main(){
	SSTable ST;
	ST.elem = (int *)malloc(11*sizeof(int));
	ST.length = 10;
	
	int a[] = {0,1,5,7,8,9,4,2,3,6,10};
	ST.elem = a;
	cout<<"Ë³Ðò²éÕÒ"<<endl;
	cout<<Search_Seq(ST,4)<<endl;

	

	int b[] = {0,1,2,3,4,5,6,7,8,9,10};
	ST.elem = b;
	cout<<"ÕÛ°ë²éÕÒ"<<endl;
	cout<<Search_Bin(ST,4,1,ST.length)<<endl;
	
	
	BiTree T=NULL;
	
	
	InsertBST(T,45);
	InsertBST(T,12);
	InsertBST(T,53);
	InsertBST(T,3);
	InsertBST(T,37);
	InsertBST(T,100);
	InsertBST(T,24);
	InsertBST(T,61);
	InsertBST(T,90);
	InsertBST(T,78);
	InOrderTraverse(T,PrintElem);
	
	cout<<endl;
	DeleteBST(T,45);
	DeleteBST(T,53);
	DeleteBST(T,24);
	
	InOrderTraverse(T,PrintElem);
	
}
