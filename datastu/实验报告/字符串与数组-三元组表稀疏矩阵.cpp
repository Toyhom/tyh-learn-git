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
#include <algorithm>



typedef struct 
{
    int i, j;
    int e;
}Triple;

typedef struct 
{
    Triple data[12500 + 1];
    int mu, nu, tu;
}TSMatrix;

Status CreateSMatrix(TSMatrix &M, int mu = 0,int nu = 0)
{
    M.mu = mu;
    M.nu = nu;
    M.tu = 0;
    return OK;
}

Status AddSMatrix(TSMatrix M, TSMatrix N, TSMatrix &Q){
    int m = M.tu;
    int n = N.tu;
    int c = 1,tu = 0;
    for (int i = 1,j = 1; i <= m || j <= n;){
        if(i > m){
            Q.data[c].i = N.data[j].i;
            Q.data[c].j = N.data[j].j;
            Q.data[c].e = N.data[j].e + 0;
            c++, j++, tu++;
        }
        else if(j > n){
            Q.data[c].i = M.data[i].i;
            Q.data[c].j = M.data[i].j;
            Q.data[c].e = M.data[i].e + 0;
            c++, i++, tu++;
        }
        else
        {
            if (M.data[i].i == N.data[j].i && M.data[i].j == N.data[j].j) {
                Q.data[c].i = M.data[i].i;
                Q.data[c].j = M.data[i].j;
                Q.data[c].e = M.data[i].e + N.data[j].e;
                c++, i++, j++, tu++;
            }
            else if (M.data[i].i < N.data[j].i)
            {
                Q.data[c].i = M.data[i].i;
                Q.data[c].j = M.data[i].j;
                Q.data[c].e = M.data[i].e + 0;
                c++, i++, tu++;
            }
            else if (M.data[i].i == N.data[j].i){
                if (M.data[i].j <= N.data[j].j){
                    Q.data[c].i = M.data[i].i;
                    Q.data[c].j = M.data[i].j;
                    Q.data[c].e = M.data[i].e + 0;
                    c++, i++, tu++;
                }
                else
                {
                    Q.data[c].i = N.data[j].i;
                    Q.data[c].j = N.data[j].j;
                    Q.data[c].e = N.data[j].e + 0;
                    c++, j++, tu++;
                }
                
            }
            else{
                    Q.data[c].i = N.data[j].i;
                    Q.data[c].j = N.data[j].j;
                    Q.data[c].e = N.data[j].e + 0;
                    c++, j++, tu++;
            }            
        }
    }
    Q.mu = M.mu;
    Q.nu = M.nu;
    Q.tu = tu;
    return OK;
}

Status TransposeSMatrix(TSMatrix M,TSMatrix &T){
    T.mu = M.nu;
    T.nu = M.mu;
    T.tu = M.tu;
    if(T.tu){
        int q = 1;
        for (int c = 1; c <= M.nu;c++){
            for (int p = 1; p <= M.tu;p++){
                if(M.data[p].j == c){
                    T.data[q].i = M.data[p].j;
                    T.data[q].j = M.data[p].i;
                    T.data[q].e = M.data[p].e;
                    q++;
                    }
            }
        }
    }
    return OK;
}

Status PrintSMatrix(TSMatrix M){
    int m = 1;
    for (int i = 1; i <= M.mu; i++)
    {
        for(int j = 1; j <= M.nu; j++)
        {
            if (M.data[m].i == i && M.data[m].j == j) {
                cout << M.data[m].e << " ";
                m++;
            }
            else
            {
                cout << 0 << " ";
            }
            
        }
        cout << '\n';
    }
}

bool cmp(const Triple a, const Triple b)
{
    if(a.i == b.i)
        return a.j < b.j;
    return a.i < b.i;
}

Status AssignSMatrix(TSMatrix &M,int i,int j,int e){
    int tu = M.tu;
    tu++;
    M.data[tu].i = i;
    M.data[tu].j = j;
    M.data[tu].e = e;
    M.tu = tu;
    sort(M.data + 1, M.data + M.tu + 1, cmp);
    return OK;
}




int main(){
    int i = 1;
    TSMatrix M,N,Q,T;
    CreateSMatrix(M, 3, 3);
    AssignSMatrix(M, 1, 1, 1);
    AssignSMatrix(M, 2, 2, 2);
    AssignSMatrix(M, 3, 3, 3);

    CreateSMatrix(N, 3, 3);
    AssignSMatrix(N, 1, 2, 4);
    AssignSMatrix(N, 1, 1, 5);
    AssignSMatrix(N, 1, 3, 3);
    AssignSMatrix(N, 2, 1, 5);
    AssignSMatrix(N, 2, 2, 4);
    AssignSMatrix(N, 2, 3, 3);
    AssignSMatrix(N, 3, 1, 5);
    AssignSMatrix(N, 3, 2, 4);
    AssignSMatrix(N, 3, 3, 3);
	
	cout<<"数组M:"<<endl;
    PrintSMatrix(M);
    
    
    cout << '\n';
    cout<<"数组N:"<<endl;
    PrintSMatrix(N);
    cout << '\n';
    CreateSMatrix(Q, 3, 3);

    AddSMatrix(M, N, Q);
	cout<<"数组Q=M+N:"<<endl; 
    PrintSMatrix(Q);
    cout << '\n';

    CreateSMatrix(T, 3, 3);
	
    TransposeSMatrix(Q, T);
	cout<<"数组Q的转置:"<<endl;
    PrintSMatrix(T);
    cout << '\n';

    system("pause");
}
