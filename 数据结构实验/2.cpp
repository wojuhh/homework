#include <iostream>
using namespace std;

typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode, *LinkList;

LinkList insertList(LinkList &L, int x)
{
    LinkList q=(LinkList)malloc(sizeof(LNode));
    q->data=x;
    q->next=NULL;
    LinkList p=L;
    while(p->next!=NULL)p=p->next;
    p->next=q;
    return L;
}

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
}

void output(LinkList &L)
{
    LinkList p=L->next;
    while(p!=NULL)
    {
        cout<<p->data<<",";
        p=p->next;
    }
}

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
