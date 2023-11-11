#include<iostream>
#include<string>
#include<stack>
using namespace std;
#define MAXSIZE 15
typedef string SqBiTree[MAXSIZE];
SqBiTree bt;

int length() {
    int i = 1;
    while(i < MAXSIZE && bt[i] != "") {
        i++;
    }
    return i-1;
}       //求二叉树的长度

void InOrder() {
    stack<int> s;
    int k=length();
    int i = 1;
    while(i < k || !s.empty()) {
        while(i < MAXSIZE && (bt[i] != "None" && bt[i] != "")) {
            s.push(i);
            i = 2 * i;
        }
        if(!s.empty()) {
            i = s.top();
            s.pop();
            cout << bt[i] << " ";
            i = 2 * i + 1;
        }
    }
    cout << endl;
}   //中序遍历,用栈实现

int main(){
    int i = 2;
    cin >> bt[1];
    char c;
    while(c=getchar(),c!='\n') {
        cin >> bt[i];
        i++;
    }
    bt[i] = "None";    //用None表示空结点
    InOrder();
    return 0;
}
