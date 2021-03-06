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
}ArcNode;//边

typedef struct VNode
{
	vertextype vertex;
	ArcNode *firstedge;
}VNode;//顶点

typedef struct
{
	VNode adjlist[maxnum];
	int vertexnum,edgenum;
}ALgraph;//图

typedef struct
{
	VNode data[maxnum];
	int front,rear;
}seqqueue,*Pseqqueue;//队列的定义


//图的创建函数

void creat(ALgraph *g)
{
	int i,j,k;
	ArcNode *p,*q;
	printf("请输入图的顶点数和弧数\n");
	scanf("%d,%d",&(g->vertexnum),&(g->edgenum));//输入要用逗号隔开
	printf("请输入顶点信息\n");
	fflush(stdin);
	for(i=0;i<g->vertexnum;i++)
	{
		scanf("%c",&(g->adjlist[i].vertex));
		g->adjlist[i].firstedge=NULL;
	}
	fflush(stdin);
	printf("请输入边数据\n");
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

//还有一个简单的visit函数即输出函数

void visit(ALgraph g,int v)
{
	printf("%c",g.adjlist[v].vertex);
}

//我先介绍深度遍历函数，深度遍历相对于广度比较简单，采用递归的方法

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

//然后是广度遍历(队列)

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
		printf("队满");
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
		//printf("队空");
		return -1;
	}
	else
	{
		q->front++;
		*x=q->data[q->front];
		return 1;
	}

}

//然后就可以编写广度遍历函数

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

//最后使用main函数将上面的函数串联起来就偶k了

main()
{
	ALgraph g;
	creat(&g);
	printf("深度优先遍历:");
	dfstravel(g);
	printf("\n广度优先遍历:");
	bfs(g,0);
	printf("\n");
}

