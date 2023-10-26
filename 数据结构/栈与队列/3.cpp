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

bool InitStack(SqStack &S){
    S.base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
    if(!S.base) return false;
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return true;
}   

bool Push(SqStack &S, SElemType e){
    if(S.top - S.base >= S.stacksize){
        S.base = (SElemType *)realloc(S.base, (S.stacksize + STACKINCREMENT)*sizeof(SElemType));
        if(!S.base) return false;
        S.top = S.base + S.stacksize;
        S.stacksize += STACKINCREMENT;
    }
    *S.top++ = e;
    return true;
}  

bool Pop(SqStack &S,SElemType &e){
    if(S.top == S.base) return false;
    e = *S.base++;
    return true;
}   

int main(){
    SqStack S;
    InitStack(S);
    int n;
    cin >> n;
    SElemType num;
    for(int i=0;i<n;i++){
        cin >> num;
        Push(S,num);
    }
    cin >> n;
    char c;
    for(int i=0;i<n;i++){
        cin >> c;
        if(c =='D'){
            Pop(S,num);
            cout << num << endl;
        }
        else {
            c= c-'0';
            Push(S,c);
        } 
    }
    return 0;
}
