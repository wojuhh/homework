#include <iostream>
using namespace std;
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef char SElemType;     //定义栈元素类型

typedef struct{            //定义顺序栈结构
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;                //定义顺序栈类型

bool InitStack(SqStack &S){
    S.base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
    if(!S.base) return false;
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return true;
}   //初始化栈

char Push(SqStack &S, SElemType e){
    if(S.top - S.base >= S.stacksize){
        S.base = (SElemType *)realloc(S.base, (S.stacksize + STACKINCREMENT)*sizeof(SElemType));
        if(!S.base) return false;
        S.top = S.base + S.stacksize;
        S.stacksize += STACKINCREMENT;
    }
    *S.top++ = e;
    return true;
}   //入栈

char Pop(SqStack &S, SElemType &e){
    if(S.top == S.base) return false;
    e = *--S.top;
    return true;
}   //出栈

char GetTop(SqStack S, SElemType &e){
    if(S.top == S.base) return false;
    e = *(S.top - 1);
    return true;
}   //取栈顶元素

bool PMatch(char a,char b){
    if(a == '(' && b == ')') return true;
    else if(a == '[' && b == ']') return true;
    else if(a == '{' && b == '}') return true;
    else return false;
}

int main(){
    SqStack S;
    InitStack(S);
    char c;
    char e;
    while(scanf("%c", &c) != EOF){
        if(c == '(' || c == '[' || c == '{'){
            Push(S, c);
        }
        else if(c == ')' || c == ']' || c == '}'){
            if(GetTop(S, e) && PMatch(e, c)){
                Pop(S, e);
            }
            else{
                cout << 0 << endl;
                return 0;
            }
        }
    }
    if(S.top == S.base){
        cout << 1 << endl;
    }
    else{
        cout << 0 << endl;
    }
    return 0;
}