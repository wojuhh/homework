#include<iostream>
using namespace std;

/*typedef struct QNode{
    int data;
    struct QNode *next;
};

typedef struct{
    QNode *front;
    QNode *rear;
}LinkQueue;*/

#define MAXSIZE 1200

typedef struct{
    int* base;
    int* top;
    int stacksize;
}SqStack;   //顺序栈

void InitStack(SqStack &S){
    S.base = (int *)malloc(MAXSIZE*sizeof(int));
    if(!S.base) return;
    S.top = S.base;
    S.stacksize = MAXSIZE;
}       //初始化栈

void Push(SqStack &S, int e){
    if(S.top - S.base >= S.stacksize){
        S.base = (int *)realloc(S.base, (S.stacksize+MAXSIZE)*sizeof(int));
        if(!S.base) return;
        S.top = S.base + S.stacksize;
        S.stacksize += MAXSIZE;
    }
    *S.top++ = e;
}    //入栈

void Pop(SqStack &S, int &e){
    if(S.top == S.base) return;
    e = *--S.top;
}   //出栈

typedef struct{
    int data[MAXSIZE];
    int front;
    int rear;
}SqQueue;   //顺序队列

void InitQueue(SqQueue &Q){
    Q.front = Q.rear = 0; 
}   //初始化队列

void EnQueue(SqQueue &Q,int x){
    if((Q.rear+1)%MAXSIZE == Q.front)
        return;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear+1)%MAXSIZE;
}   //入队

void DeQueue(SqQueue &Q,int &x){
    if(Q.front == Q.rear)
        return;
    x = Q.data[Q.front];
    Q.front = (Q.front+1)%MAXSIZE;
}   //出队

int main(){
    int n;
    cin>>n;

    SqStack S;
    SqQueue Q;
    InitQueue(Q);
    InitStack(S);
    
    for(int i = 0;i < n;i++){
        int x;
        cin>>x;
        EnQueue(Q,x);
    }   //入队
    
    while(Q.front != Q.rear){
        int x;
        DeQueue(Q,x);
        Push(S,x);
    }   //出队入栈
    
    while(S.top != S.base){
        int x;
        Pop(S,x);
        cout<<x<<" ";
    }   //出栈输出
    
    return 0;
}   //逆序输出