#include"stdio.h"
#include"stdlib.h"
#define maxnum 30
#define false 0
#define true 1
int visited[maxnum];
typedef char vertextype;
typedef int infotype;

typedef struct ArcNode
{

	int adjvex;
	infotype info;
	struct ArcNode *next;
}ArcNode;//��

typedef struct VNode
{
	vertextype vertex;
	ArcNode *firstedge;
}VNode;//����

typedef struct
{
	VNode adjlist[maxnum];
	int vertexnum,edgenum;
}ALgraph;//ͼ

typedef struct
{
	VNode data[maxnum];
	int front,rear;
}seqqueue,*Pseqqueue;//���еĶ���


//ͼ�Ĵ�������

void creat(ALgraph *g)
{
	int i,j,k;
	ArcNode *p,*q;
	printf("������ͼ�Ķ������ͻ���\n");
	scanf("%d,%d",&(g->vertexnum),&(g->edgenum));//����Ҫ�ö��Ÿ���
	printf("�����붥����Ϣ\n");
	fflush(stdin);
	for(i=0;i<g->vertexnum;i++)
	{
		scanf("%c",&(g->adjlist[i].vertex));
		g->adjlist[i].firstedge=NULL;
	}
	fflush(stdin);
	printf("�����������\n");
	for(k=0;k<g->edgenum;k++)
	{
		scanf("%d,%d",&i,&j);
		p=(ArcNode *)malloc(sizeof(ArcNode));
		p->adjvex=j;
		if(g->adjlist[i].firstedge==NULL)
			g->adjlist[i].firstedge=p;
		else
		{
			q->next=p;
	
		}
		q=p;
		p->next=NULL;
	}
}

//����һ���򵥵�visit�������������

void visit(ALgraph g,int v)
{
	printf("%c",g.adjlist[v].vertex);
}

//���Ƚ�����ȱ�����������ȱ�������ڹ�ȱȽϼ򵥣����õݹ�ķ���

void dfs(ALgraph g,int v)
{
	ArcNode *p;
	int w; 
	visit(g,v);
	visited[v]=true;
	for(p=g.adjlist[v].firstedge;p;p=p->next)
	{
		w=p->adjvex;
		if(!visited[w])
		dfs(g,w);
	}
}

void dfstravel(ALgraph g)
{
	int v;
	for(v=0;v<g.vertexnum;v++)
		visited[v]=false;
	for(v=0;v<g.vertexnum;v++)
		if(!visited[v])
			dfs(g,v);
}

//Ȼ���ǹ�ȱ���(����)

Pseqqueue init()
{
	Pseqqueue q;
	q=(Pseqqueue)malloc(sizeof(seqqueue));
	if(q)
	{
		q->front=0;
		q->rear=0;
	}
	return q;
}

int empty(Pseqqueue q)
{
	if(q&&q->front==q->rear)
	return 1;
	else
	return 0;
}

int in(Pseqqueue q,ALgraph g,int v)
{
	if((q->rear+1)%maxnum==q->front)
	{
		printf("����");
		return -1;
	}
	else
	{
		q->rear++;
		q->data[q->rear]=g.adjlist[v];
		return 1;
	}
}

int out(Pseqqueue q,VNode *x)
{
	if(empty(q))
	{
		//printf("�ӿ�");
		return -1;
	}
	else
	{
		q->front++;
		*x=q->data[q->front];
		return 1;
	}

}

//Ȼ��Ϳ��Ա�д��ȱ�������

void bfs(ALgraph g,int v)
{
	ArcNode *p;
	int w;
	VNode u;
	Pseqqueue q;
	q=init();
	visit(g,v);
	visited[v]=true;
	in(q,g,v);
	int v1;
	for(v1=0;v1<g.vertexnum;v1++)
	visited[v1]=false;
	while(!empty(q))
	{
		out(q,&u);
		for(p=u.firstedge;p;p=p->next)
		{
			w=p->adjvex;
			if(!visited[w])
			{
				visit(g,w);
				visited[w]=true;
				in(q,g,w);
			}
		}
	}


}

//���ʹ��main����������ĺ�������������żk��

main()
{
	ALgraph g;
	creat(&g);
	printf("������ȱ���:");
	dfstravel(g);
	printf("\n������ȱ���:");
	bfs(g,0);
	printf("\n");
}

