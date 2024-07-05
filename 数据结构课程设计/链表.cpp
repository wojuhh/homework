#include<iostream>
#include<windows.h>
#include<algorithm>
#define MAXQSIZE 100
using namespace std;

struct LNode {
    int data;
    LNode* next;
};          //单链表结点类型

void CreateList(LNode*& L, int n) {
    L = (LNode*)malloc(sizeof(LNode));
    L->next = L;
    L->data = 1;
    LNode* p = L;
    for (int i = 2; i <= n; i++) {
        LNode* q = (LNode*)malloc(sizeof(LNode));
        q->data = i;
        q->next = p->next;
        p->next = q;
        p = q;
    }
    p->next = L;
}       //创建循环单链表

//以下为舞曲配对的实现
void DancePartner(LNode* L1, LNode* L2, int n, int mi) {
    int round = 1;
    LNode* p, * q;
    p = L1;
    q = L2;
    while (round <= n) {
        cout << "--------------------" << endl;
        cout << "第" << round << "轮配对：" << endl;
        int k = 0;

        while (k < mi) {
            k++;
            Sleep(100);
            cout << p->data << "号男生和" << q->data << "号女生" << endl;
            p = p->next;
            q = q->next;

            Sleep(100);
        }
        round++;
    }
}       //一般配对

void dancePartner(LNode* L1, LNode* L2, int n, int m) {
    int round[10];      //记录相遇的舞曲
    int e1, e2;
    for (int i = 0; i < 10; i++) {
        round[i] = 0;
    }
    int k = 0;
    int i = 0;
    LNode* p, * q;
    p = L1;
    q = L2;
    int roundnum = 1;
    int mi = min(n, m);
    while (true) {      //循环直到找到10首相遇的舞曲
        k = 0;
        while (k < mi) {
            k++;
            e1 = p->data;
            e2 = q->data;
            p = p->next;
            q = q->next;
            if (e1 == n && e2 == m) {
                round[i] = roundnum;
                i++;
            }
            if (i == 10)break;
        }
        roundnum++;
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
    LNode* L1, * L2;
    CreateList(L1, n);
    CreateList(L2, m);
    int mi = min(n, m);     //最小值
    while (true) {
        int choice;
        cout << "--------------------" << endl;
        cout << "请选择配对方式：" << endl;
        cout << "1.一般配对" << endl;
        cout << "2.特殊配对" << endl;
        cout << "0.退出" << endl;
        cout << "请输入编号:";
        cin >> choice;
        switch (choice) {
        case 1:     //一般配对
            cout << "--------------------" << endl;
            cout << "请输入总舞曲数：";
            int num;
            cin >> num;
            if (num <= 0) {
                cout << "输入错误！" << endl;
                continue;
            }
            DancePartner(L1, L2, num, mi);
            continue;
        case 2:     //特殊配对
            cout << "--------------------" << endl;
            cout << "请输入要配对的男生编号：";
            int ma;
            cin >> ma;
            if (ma > n || ma <= 0) {
                cout << "输入错误！" << endl;
                continue;
            }
            cout << "请输入要配对的女生编号：";
            int f;
            cin >> f;
            if (f > m || f <= 0) {
                cout << "输入错误！" << endl;
                continue;
            }
            dancePartner(L1, L2, ma, f);
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