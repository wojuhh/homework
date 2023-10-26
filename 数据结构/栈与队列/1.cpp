#include<iostream>
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

bool Push(SqStack &S, SElemType e){
    if(S.top - S.base >= S.stacksize){
        S.base = (SElemType *)realloc(S.base, (S.stacksize + STACKINCREMENT)*sizeof(SElemType));
        if(!S.base) return false;
        S.top = S.base + S.stacksize;
        S.stacksize += STACKINCREMENT;
    }
    *S.top++ = e;
    return true;
}   //入栈

bool Pop(SqStack &S, SElemType &e){
    if(S.top == S.base) return false;
    e = *--S.top;
    return true;
}   //出栈

bool GetTop(SqStack S, SElemType &e){
    if(S.top == S.base) return false;
    e = *(S.top - 1);
    return true;
}   //取栈顶元素

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
}   //比较运算符优先级

int main(){
    SqStack OPTR;   //定义运算符栈
    
    InitStack(OPTR);    //初始化栈
    
    Push(OPTR, '#');    //初始化栈顶元素为#
    char c;
    c=getchar();
    while(c!='#'){
        if(c>='A'&&c<='Z'){
            cout<<c;
            c=getchar();
        }   //如果是操作数则输出
        else{
            char theta;
            int flag=0;
            while(1){
                GetTop(OPTR, theta);
                switch(Precede(theta, c)){
                    case '<':
                        Push(OPTR, c);
                        c=getchar();
                        flag=1;
                        break;
                    case '=':
                        Pop(OPTR, theta);
                        c=getchar();
                        flag=1;
                        break;
                    case '>':
                        Pop(OPTR, theta);
                        cout<<theta;
                        break;
                }
                if(flag) break;
            }       //如果是运算符则与栈顶元素比较优先级，根据优先级进行相应操作
        }
    }   //读入字符，判断是运算符还是操作数，是操作数则输出，是运算符则与栈顶元素比较优先级，根据优先级进行相应操作
    while(OPTR.top!=OPTR.base+1){
        char theta;
        Pop(OPTR, theta);
        cout<<theta;
    }   //输出栈中剩余运算符
    return 0;   
}