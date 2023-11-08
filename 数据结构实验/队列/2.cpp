#include<iostream>
using namespace std;

typedef struct QNode{
    int monkey;
    int peach;
    struct QNode *next;
};  //循环链表

typedef struct{
    QNode *front;
    QNode *rear;
}LinkQueue;     //队列

void InitQueue(LinkQueue &Q){
    QNode *p = (QNode *)malloc(sizeof(QNode));
    p->monkey = 1;
    p->peach = 0;
    p->next = p;
    Q.front = p;
    Q.rear = p;
}       //初始化队列

void EnQueue(LinkQueue &Q, int x, int y){
    QNode *p = (QNode *)malloc(sizeof(QNode));
    p->monkey = x;
    p->peach = y;
    p->next = Q.front;
    Q.rear->next = p;
    Q.rear = p;
}       //入队

void DeQueue(LinkQueue &Q, int &x, int &y){
    if(Q.front == Q.rear){
        x = Q.front->monkey;
        y = Q.front->peach;
        Q.front = NULL;
        Q.rear = NULL;
        return;
    }
    QNode *p = Q.front;
    x = p->monkey;
    y = p->peach;
    Q.front = Q.front->next;
    Q.rear->next = Q.front;
    free(p);
}       //出队

/**
 * 猴子分桃
 * @param Q 队列
 * @param n 猴子数目
 * @param m 每次报数的数目
 * @param k 最后剩余的猴子数目
 */
void DividePeach(LinkQueue &Q, int n, int m, int k){
    for(int i = 2;i <= n;i++){
        EnQueue(Q, i, 0);
    }
    int sum = 0;
    int num = 1;
    while(Q.front != Q.rear){
        if(num == k+1) num = 1;
        int x,y;
        DeQueue(Q, x, y);
        if(y == m){
            cout << x << " ";
            num++;
        }
        else if(y > m){
            sum = sum + y - m;
            sum = sum + num;
            cout << x << " ";
            num++;
        }
        else{
            sum = sum + num;
            if(m - y <= sum){
               sum = sum - m + y;
               cout << x << " ";
            }else{
                y = y + sum;
                sum = 0; 
                EnQueue(Q, x, y);
            }
            num++;
        }
    }       //循环结束，队列中只剩下一个元素
    int x,y;
    DeQueue(Q, x, y);
    cout << x << endl;
}

int main(){
    int n, k, m;
    cin >> n >> k >> m;
    LinkQueue Q;
    InitQueue(Q);
    DividePeach(Q, n, m, k);

    return 0;
}