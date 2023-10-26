#include <iostream>
#include<cmath>
#include <stdio.h>
#include <stdlib.h>
#include<iomanip>
using namespace std;

typedef int ElemType;  //定义元素类型

typedef struct LNode   //结点结构
{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;   //LNode是结点名，LinkList是指向结点的指针

LinkList cList(int n){
	LinkList L = (LinkList)malloc(sizeof(LNode));
    L->data = 1;
	LinkList p = L;
	for(int i=2;i<=n;i++){
		LinkList q = (LinkList)malloc(sizeof(LNode));
		q->data = i;
		q->next = NULL;
		p->next = q;

		p = p->next;
	}
	p->next = L;
	return L;
}   //创建循环链表

LinkList insertlist(LinkList L, int n) {
	LinkList p = L;
	while (p->next != L) {
		p = p->next;
	}
	LinkList q = (LinkList)malloc(sizeof(LNode));
	q->data = n;
	q->next = L;
	p->next = q;
	return L;
}   //在链表尾部插入结点

LinkList NewList(LinkList L,int n){
	LinkList p=(LinkList)malloc(sizeof(LNode));
	p->next=p;
	int i=1;
	int count=0;
	while(L->next!=L){
		if(i==n-1){
			LinkList q=L->next;
			L->next=q->next;
            if(count==0){
                p->data=q->data;
                count++;
                L=L->next;
            }
            else{
                insertlist(p,q->data);
                L=L->next;
            }
			free(q);
			i=1;
		}
		else{
			L=L->next;
			i++;
		}
	}   //根据输入的n值，将链表中的结点删除，并且插入到新链表中
    if(count==0){
        p->data=L->data;
    }
    else{
        insertlist(p,L->data);
    }
	free(L);
	return p;
}   //约瑟夫环,返回新链表

void output(LinkList L) {
	LinkList p = L;
	while (p->next != L) {
		cout << setw(4) << p->data;
		p = p->next;
	}
	cout << setw(4) << p->data;
}   //输出链表

int main()
{
	int num;
	cin>>num;
	LinkList L=cList(num);  //创建循环链表
	while(1){
        int temp;
        if (scanf("%d", &temp) == EOF)break;
		if (temp == 10086) break; 
        if(temp==-1)break;
        if(temp==0)break;
        if(temp==1)continue;
        L=NewList(L,temp);
    }   //输入数据
	output(L);  //输出数据
	return 0;
}