#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

using namespace std;

typedef int Status;
typedef int VertexType;

#include <algorithm>
#include <iostream>
#include <malloc.h>
#include <stdio.h>

typedef struct ArcNode{
	int adjvex;
	struct ArcNode *nextarc;
	int *info;
}ArcNode;

typedef struct VNode{
	VertexType data;
	ArcNode *firstarc;
	bool visited;
}VNode,AdjList[20];  //zero have value

typedef struct {
	AdjList vertices;
	int vexnum,arcnum;
	//int kind;
}ALGraph;

Status CreateALGraph(ALGraph &G){
	int IncInfo;
	cout<<"输入顶点数和边数：";
	cin>>G.vexnum>>G.arcnum;
	
	cout<<"输入点数据：";
	for(int i = 0;i<G.vexnum;i++){
		cin>>G.vertices[i].data;
		G.vertices[i].firstarc = NULL;
	}
	cout<<"输入边数据：";
	for(int k=0;k<G.arcnum;k++){
		int v1,v2;
		cin>>v1>>v2;
		//cout<<"OK1";
		if(G.vertices[v1].firstarc == NULL){
		
		G.vertices[v1].firstarc = (ArcNode *)malloc(sizeof(ArcNode));
		G.vertices[v1].firstarc->adjvex = v2;
		//cout<<"OK5";	
		G.vertices[v1].firstarc->nextarc = NULL;
		//cout<<"OK6";
		G.vertices[v1].firstarc->info = 0;
		//cout<<"OK2";
		} 
		else{
		ArcNode *p = G.vertices[v1].firstarc;	
		while(p){
			p = p->nextarc;
		}
		
		p = (ArcNode *)malloc(sizeof(ArcNode));
		p->adjvex = v2;	
		p->nextarc = NULL;
		p->info = 0;	
			
			
		}

	}
}

Status PrintElem(ALGraph G,int e){
    cout << G.vertices[e].data;
    return OK;
}

//Boolean visited[20];
//Status (*VisitFunc)(int v);


int  FirstAdjVex(ALGraph &G,int v){
	if(!G.vertices[v].firstarc) return -1;
	else return G.vertices[v].firstarc->adjvex;
}

int  NextAdjVex(ALGraph &G,int v,int w){
	ArcNode *p = G.vertices[v].firstarc;
	while(p->nextarc){
		if(p->adjvex == w){
			return p->nextarc->adjvex;
		}
		else p = p->nextarc;
	}
	return -1;
}

void DFS(ALGraph &G,int v,Status (*Visit)(ALGraph G,int v));

void DFSTraverse(ALGraph &G,Status (*Visit)(ALGraph G,int v)){
	
	for(int v=0;v<G.vexnum;v++) G.vertices[v].visited = false;
	for(int v=0;v<G.vexnum;v++){
		if(!G.vertices[v].visited) DFS(G,v,Visit);
	}
	
	//for(int v=0;v<G.vexnum;v++) G.vertices[v].visited = false;
}

void DFS(ALGraph &G,int v,Status (*Visit)(ALGraph G,int v)){
	G.vertices[v].visited = true;
	Visit(G,v);
	
	
	for(int w = FirstAdjVex(G,v);w>=0;w = NextAdjVex(G,v,w)){
		if(!G.vertices[w].visited) DFS(G,w,Visit);
	}
}



int main(){
	ALGraph G;
	CreateALGraph(G); // vexnum,arcnum,data,v1,v2
	
	//Gsetnum(G);
	//Gsetdata(G,v);
	
	
	DFSTraverse(G,PrintElem);
	
	
}




