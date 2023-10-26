#include<iostream>
using namespace std;
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int SElemType;  

typedef struct{
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;   

int InitStack(SqStack &S){
    S.base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
    if(!S.base) return 0;
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return 1;
}

int Push(SqStack &S, SElemType e){
    if(S.top - S.base >= S.stacksize){
        S.base = (SElemType *)realloc(S.base, (S.stacksize + STACKINCREMENT)*sizeof(SElemType));
        if(!S.base) return 0;
        S.top = S.base + S.stacksize;
        S.stacksize += STACKINCREMENT;
    }
    *S.top++ = e;
    return 1;
}

int Pop(SqStack &S, SElemType &e){
    if(S.top == S.base) return 0;
    e = *--S.top;
    return 1;
}

bool StackEmpty(SqStack S){
    if(S.top == S.base) return true;
    return false;
}

void conversion(int n,int x){
    SqStack S;
    InitStack(S);
    while(n){
        Push(S, n%x);
        n = n/x;
    }
    while(!StackEmpty(S)){
        SElemType e;
        Pop(S, e);
        if(e >= 10 && e < 16) cout << char(e-10+'A');
        else cout << e;
    }
    cout << endl;
}

int main(){
    int n, x;
    cin >> n >> x;
    conversion(n, x);
    return 0;
}