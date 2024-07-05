#include<iostream>
#include<windows.h>
#include<algorithm>
#define MAXQSIZE 100
using namespace std;

typedef struct {
    int* base;
    int front;
    int rear;
}SqQueue;       //循环队列类型

bool InitQueue(SqQueue& Q) {
    Q.base = (int*)malloc(MAXQSIZE * sizeof(int));
    if (!Q.base)return false;
    Q.front = Q.rear = 0;
    return true;
}       //初始化队列

int QueueLength(SqQueue Q) {
    return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}       //求队列长度

bool EnQueue(SqQueue& Q, int e) {
    if ((Q.rear + 1) % MAXQSIZE == Q.front)return false;
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXQSIZE;
    return true;
}       //入队

bool DeQueue(SqQueue& Q, int& e) {
    if (Q.front == Q.rear)return false;
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAXQSIZE;
    return true;
}       //出队
//以上为队列的基本操作

//以下为舞曲配对的实现
void dancePartner(SqQueue Q1, SqQueue Q2, int n) {
    int round = 1;
    int mi = min(QueueLength(Q1), QueueLength(Q2));     //取两队列长度的最小值
    while (round <= n) {
        cout << "--------------------" << endl;
        cout << "第" << round << "轮配对：" << endl;
        int k = 0;
        while (k < mi) {
            int e1, e2;
            k++;
            DeQueue(Q1, e1);
            DeQueue(Q2, e2);
            Sleep(100);
            cout << e1 << "号男生和" << e2 << "号女生" << endl;
            EnQueue(Q1, e1);
            EnQueue(Q2, e2);
            Sleep(100);
        }
        round++;
    }       
}       //一般配对

void dancePartner(SqQueue Q1, SqQueue Q2, int n, int m) {
    int round[10];      //记录相遇的舞曲数
    int e1, e2;
    for (int i = 0; i < 10; i++) {
        round[i] = 0;
    }
    int k = 0;
    int i = 0;
    int mi = min(QueueLength(Q1), QueueLength(Q2));     //取两队列长度的最小值
    int roundNum = 1;
    while (true){
        k=0;
        while (k < mi) {
            int e1, e2;
            k++;
            DeQueue(Q1, e1);
            DeQueue(Q2, e2);
            EnQueue(Q1, e1);
            EnQueue(Q2, e2);
            if (e1 == n && e2 == m) {
                round[i] = roundNum;
                i++;
            }
            if (i == 10)break;
        }
        roundNum++;
        if (i == 10)break;
    }
    cout << "--------------------" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "他们于第" << round[i] << "首舞曲相遇" << endl;
    }
}       //特殊配对

int main() {
    cout << "--------------------" << endl;
    cout << "  欢迎来到舞曲配对" << endl;
    cout << "--------------------" << endl;
    cout << "请输入男生数量：";
    int n;
    cin >> n;
    cout << "请输入女生数量：";
    int m;
    cin >> m;
    SqQueue Q1, Q2;
    InitQueue(Q1);
    InitQueue(Q2);
    for (int i = 1; i <= n; i++) {
        EnQueue(Q1, i);
    }
    for (int i = 1; i <= m; i++) {
        EnQueue(Q2, i);
    }
    while (true) {
        int choice;
        cout << "--------------------" << endl;
        cout << "请选择配对方式：" << endl;
        cout << "1.一般配对" << endl;
        cout << "2.特殊配对" << endl;
        cout << "0.退出" << endl;
        cout << "请输入编号:";
        cin >> choice;
        switch (choice) {       //选择配对方式
        case 1:     //一般配对
            cout << "--------------------" << endl;
            cout << "请输入总舞曲数：";
            int num;
            cin >> num;
            if (num<=0) {
                cout << "输入错误！" << endl;
                continue;
            }
            dancePartner(Q1, Q2, num);
            continue;
        case 2:     //特殊配对
            cout << "--------------------" << endl;
            cout << "请输入要配对的男生编号：";
            int ma;
            cin >> ma;
            if (ma > n||ma<=0) {
                cout << "输入错误！" << endl;
                continue;
            }
            cout << "请输入要配对的女生编号：";
            int f;
            cin >> f;
            if (f > m||f<=0) {
                cout << "输入错误！" << endl;
                continue;
            }
            dancePartner(Q1, Q2, ma, f);
            continue;
        case 0:     //退出
            break;
        default:        //输入错误
            cout << "输入错误！" << endl;
            continue;
        }
        break;
    }
    system("pause");
    return 0;
}