
#include <algorithm>
#include <iostream>
#include <malloc.h>
#include <stdio.h>

using namespace std;

typedef struct{
	int *elem;
	int length;
	int listsize;
}SqList; 


void InitSqList(SqList &L,int *a,int l){
	L.length = 0;
	L.listsize = 100;
	int *p = a;
	
	L.length = l;
	
	L.elem = (int *)malloc((L.length+1)*sizeof(int));

	
	for(int i = 1;i<=L.length;i++){
		L.elem[i] = p[i-1];
	}
}

void PrintSqList(SqList L){
	for(int i = 1;i<=L.length;i++){
		cout<<L.elem[i]<<" ";
	}
	cout<<endl;
}

void InsertSort(SqList &L){
	for(int i = 2;i<=L.length;i++){
		if(L.elem[i]<L.elem[i-1]){
			L.elem[0] = L.elem[i];
			L.elem[i] = L.elem[i-1];
			
			int j;
			for(j = i-2;L.elem[0]<L.elem[j];j--){
				L.elem[j+1] = L.elem[j];
			}
			L.elem[j+1]  = L.elem[0];
		}
	}
}

void BInsertSort(SqList &L){
	for(int i = 2;i<=L.length;i++){
		L.elem[0] = L.elem[i];
		int low = 1; int high = i-1;
		while(low<=high){
			int m = (low+high)/2;
			if(L.elem[0] < L.elem[m]) high = m-1;
			else low = m+1;
			
		}
		for(int j=i-1;j>=high+1;j--) L.elem[j+1] = L.elem[j];
		L.elem[high+1] = L.elem[0];
	}
}

int Partition(SqList &L,int low,int high){
	int pivo = L.elem[low];
	while(low<high){
		while(low<high&&L.elem[high]>=pivo) high--;
		int z = L.elem[low];
		L.elem[low] = L.elem[high];
		L.elem[high] = z;
		
		while(low<high&&L.elem[low]<=pivo) low++;
		z = L.elem[low];
		L.elem[low] = L.elem[high];
		L.elem[high] = z;
		
	}
	return low;
}

void QSort(SqList &L,int low,int high){
	if(low < high){
		int pivotloc = Partition(L,low,high);
		QSort(L,low,pivotloc-1);
		QSort(L,pivotloc+1,high);
	}
}


int SelectMinKey(SqList L,int i){
	int max = 10000000;
	int m = -1;
	for(int a=i;a<=L.length;a++){
		if(L.elem[a] < max){
			max = L.elem[a];
			m = a;
		}
	}
	return m;
} 

void SelectSort(SqList &L){
	for(int i = 1;i<L.length;i++){
		int j = SelectMinKey(L,i);
		if(i!=j) {
			int z = L.elem[i];
			L.elem[i] = L.elem[j];
			L.elem[j] = z;			
		}
	}
}

int main(){
	int a[] = {49,38,65,97,76,13,27};
	
	SqList L;
	
	cout<<"²åÈëÅÅÐò£º"<<endl;
	InitSqList(L,a,7);
	PrintSqList(L);
	InsertSort(L);
	PrintSqList(L);
	
	
	cout<<"ÕÛ°ë²åÈëÅÅÐò£º"<<endl;
	InitSqList(L,a,7);
	PrintSqList(L);
	BInsertSort(L);
	PrintSqList(L);
	
	cout<<"¿ìËÙÅÅÐò£º"<<endl;
	InitSqList(L,a,7);
	PrintSqList(L);
	QSort(L,1,L.length);
	PrintSqList(L);
	
	cout<<"Ñ¡ÔñÅÅÐò£º"<<endl;
	InitSqList(L,a,7);
	PrintSqList(L);
	SelectSort(L);
	PrintSqList(L);
}
