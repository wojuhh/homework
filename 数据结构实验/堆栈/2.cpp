#include<iostream>
using namespace std;
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef char SElemType;

typedef struct{
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;   

char InitStack(SqStack &S){
    S.base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
    if(!S.base)return 0;
    S.top=S.base;
    S.stacksize=STACK_INIT_SIZE;
    return 1;
}

char Push(SqStack &S,SElemType e){
    if(S.top-S.base>=S.stacksize){
        S.base=(SElemType *)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(SElemType));
        if(!S.base)return 0;
        S.top=S.base+S.stacksize;
        S.stacksize+=STACKINCREMENT;
    }
    *S.top++=e;
    return 1;
}

bool huiwen(SqStack S){
    SElemType* p=S.base;
    SElemType* q=S.top-1;
    while(p<q){
        if(*p!=*q)return false;
        p++;
        q--;
    }
    return true;
}   

int main(){
    SqStack S;
    InitStack(S);
    char c;
    while(scanf("%c",&c)!=EOF){
        Push(S,c);
    }
    if(huiwen(S))cout<<"RIGHT"<<endl;
    else cout<<"WRONG"<<endl;
    return 0;
}