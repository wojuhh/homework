#include<iostream>
using namespace std;

struct BiTNode{
    int data;
    BiTNode *lchild,*rchild;
};

bool SearchBST(BiTNode *T,int key,BiTNode *f,BiTNode *&p){
    if(!T){
        p=f;
        return false;
    }
    else if(key==T->data){
        p=T;
        return true;
    }
    else if(key<T->data){
        return SearchBST(T->lchild,key,T,p);
    }
    else{
        return SearchBST(T->rchild,key,T,p);
    }
}

void InsertBST(BiTNode *&T,int key){
    BiTNode *p=NULL;
    if(!SearchBST(T,key,NULL,p)){
        BiTNode *s=(BiTNode *)malloc(sizeof(BiTNode));
        s->data=key;
        s->lchild=s->rchild=NULL;
        if(!p){
            T=s;
        }
        else if(key<p->data){
            p->lchild=s;
        }
        else{
            p->rchild=s;
        }     
    }
    else{
        cout<<"The key is already in the tree."<<endl;
    }
}

void inOrder(BiTNode *&T){
    if(T){
        inOrder(T->lchild);
        cout<<T->data<<' ';
        inOrder(T->rchild);
    }
}

int main(){
    int n;
    cin>>n;
    BiTNode *T=NULL;
    for(int i=0;i<n;i++){
        int key;
        cin>>key;
        InsertBST(T,key);
    }
    inOrder(T);
    return 0;
}