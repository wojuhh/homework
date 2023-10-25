#include <iostream>
using namespace std;

typedef struct LNode    //定义单链表结点类型
{
    int data;
    struct LNode *next;
}LNode, *LinkList;  //LinkList为指向结构体LNode的指针类型

LinkList insertList(LinkList &L, int x)
{
    LinkList q=(LinkList)malloc(sizeof(LNode));
    q->data=x;
    q->next=NULL;
    LinkList p=L;
    while(p->next!=NULL)p=p->next;
    p->next=q;
    return L;
}   //在单链表L的末尾插入元素x

LinkList swapList(LinkList &L, int x){
    LinkList p=L->next;
    LinkList q=(LinkList)malloc(sizeof(LNode));
    q->data=x;
    if(p->data>x){
        L->next=q;
        q->next=p;
    }else{
        while(p->next!=NULL&&p->next->data<x){
            p=p->next;
        }
        q->next=p->next;
        p->next=q;
    }
    return L;
}   //将单链表L中所有小于x的元素移到大于或等于x的元素之前

void output(LinkList &L)
{
    LinkList p=L->next;
    while(p!=NULL)
    {
        cout<<p->data<<",";
        p=p->next;
    }
}   //输出单链表L

int main()
{
    int n;
    cin>>n;
    LinkList L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        insertList(L, x);
    }
    int x;
    cin>>x;
    swapList(L, x);
    output(L);
    return 0;
}
