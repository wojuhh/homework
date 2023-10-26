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

bool Pop(SqStack &S, SElemType &e){
    if(S.top == S.base) return false;
    e = *--S.top;
    return true;
}

bool GetTop(SqStack S, SElemType &e){
    if(S.top == S.base) return false;
    e = *(S.top - 1);
    return true;
}

char Precede(char a, char b){
    switch(a){
        case '+':
            switch(b){
                case '+': return '>';
                case '-': return '>';
                case '*': return '<';
                case '/': return '<';
                case '(': return '<';
                case ')': return '>';
                case '#': return '>';
            }
        case '-':
            switch(b){
                case '+': return '>';
                case '-': return '>';
                case '*': return '<';
                case '/': return '<';
                case '(': return '<';
                case ')': return '>';
                case '#': return '>';
            }
        case '*':
            switch(b){
                case '+': return '>';
                case '-': return '>';
                case '*': return '>';
                case '/': return '>';
                case '(': return '<';
                case ')': return '>';
                case '#': return '>';
            }
        case '/':
            switch(b){
                case '+': return '>';
                case '-': return '>';
                case '*': return '>';
                case '/': return '>';
                case '(': return '<';
                case ')': return '>';
                case '#': return '>';
            }
        case '(':
            switch(b){
                case '+': return '<';
                case '-': return '<';
                case '*': return '<';
                case '/': return '<';
                case '(': return '<';
                case ')': return '=';
                case '#': return ' ';
            }
        case ')':
            switch(b){
                case '+': return '>';
                case '-': return '>';
                case '*': return '>';
                case '/': return '>';
                case '(': return ' ';
                case ')': return '>';
                case '#': return '>';
            }
        case '#':
            switch(b){
                case '+': return '<';
                case '-': return '<';
                case '*': return '<';
                case '/': return '<';
                case '(': return '<';
                case ')': return ' ';
                case '#': return '=';
            }
    }
}

int main(){
    SqStack OPTR;
    SqStack OPND;
    InitStack(OPTR);
    InitStack(OPND);
    Push(OPTR, '#');
    char c;
    c==getchar();
    while(c!='#'||GetTop(OPTR, c)!='#'){
        if(c>='0'&&c<='9'){
            Push(OPND, c-'0');
            c=getchar();
        }
        else{
            char theta;
            GetTop(OPTR, theta);
            switch(Precede(theta, c)){
                case '<':
                    Push(OPTR, c);
                    c=getchar();
                    break;
                case '=':
                    Pop(OPTR, theta);
                    c=getchar();
                    break;
                case '>':
                    Pop(OPTR, theta);
                    char a, b;
                    Pop(OPND, b);
                    Pop(OPND, a);
                    //Push(OPND, Operate(a, theta, b));
                    break;
            }
        }
    }
    return 0;   
}