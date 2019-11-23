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


typedef struct{
	char *ch;
	int length;
}HString;

Status StrAssign(HString &T,char *chars){
    
    //if(T.ch) free(T.ch);
	int i = 0;
    char *c = chars;

    for(i=0,c=chars;*c;i++,c++);
	if(!i) {
	T.ch = NULL;
	T.length = 0;
	}
	else {
		T.ch = (char *)malloc(i*sizeof(char));//Òç³ö
        if(!T.ch)
            exit(OVERFLOW);
        for(int j =0;j<=i-1;j++){
			T.ch[j] = chars[j];
		} 
		T.length = i;  
	}
	return OK;
}


int StrCompare(HString S,HString T){
	for(int i=0;i<S.length && i<T.length;i++){
		if(S.ch[i]!=T.ch[i]) return S.ch[i] - T.ch[i];
	}
	return S.length - T.length;
}

Status SubString(HString &Sub,HString S,int pos,int len){
	//ERROR
	//if(Sub.ch) free(Sub.ch);
    //cout << sizeof(Sub.ch)<<" ";
    //cout << Sub.ch == NULL;
    if(!len)
    {
        Sub.ch = NULL;Sub.length = 0;
	}
	else {
		Sub.ch = (char *)malloc(len * sizeof(char));
		for(int i =0,j = pos-1;i<=len-1 && j<=pos+len-2;i++,j++){
			Sub.ch[i] =S.ch[j];
		} 
		Sub.length = len;		
	}
	return OK;
}

Status StrInsert(HString &S,int pos,HString T){
	//ERROR
	if(T.length){
		S.ch = (char *)realloc(S.ch,(S.length+T.length)*sizeof(char));
		for(int i = S.length -1;i>=pos-1;i--){
			S.ch[i+T.length] = S.ch[i];
		}
		
		for(int i = pos-1,j =0;i<=pos+T.length-2;i++,j++){
			S.ch[i] = T.ch[j];
		}
		S.length = S.length + T.length;
	}
	return OK;
	
}

Status StrDelete(HString &S,int pos,int len){
	for(int i = pos-1;i<=S.length - 2 ;i++){
		S.ch[i] = S.ch[i+len];
	}
	S.ch = (char *)realloc(S.ch,(S.length-len)*sizeof(char));
    S.length = S.length - len;
    return OK;
}

Status StrReplace(HString &S,HString T,HString V){
	int l = S.length;
	HString Sub;
    StrAssign(Sub, "");
    for(int i = 1;i<=S.length;i++){
        
        SubString(Sub,S,i,T.length);
        
        if(!StrCompare(Sub,T)){
            
            StrDelete(S,i,T.length);
            
            StrInsert(S,i,V);
            
        }
	}
}

Status StrPrint(HString S){
	for(int i=1;i<=S.length;i++){
		cout<<S.ch[i-1];
	}
	return OK;
}

int main(){
	HString S,T,V;
	//StrAssign(S,{'i',' ','l','o','v','e',' ','c','h','i','n','a','\n'});
	//StrAssign(T,{'l','o','v','e'});
	//StrAssign(V,{'l','i','k','e','s'});
    char *a = "i love china love";
    char *b = "love";
    char *c = "likes";
    
    cout<<"a:"<<a<<endl;
    cout<<"b:"<<b<<endl;
    cout<<"c:"<<c<<endl;
    
    
    StrAssign(S,a);
    StrAssign(T,b);
	StrAssign(V,c);
	StrReplace(S,T,V);
	cout<<"ÖÃ»»ºóµÄ×Ö·û´®:"<<endl;
	StrPrint(S);
	cout<<endl;
    system("pause");
}
