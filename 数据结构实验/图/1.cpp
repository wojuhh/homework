#include<iostream>
#include<queue>
using namespace std;
#define MAX_VERTEX_NUM 20

struct arc{
    int data;
    arc *nextarc;
};

struct head{
    int data;
    arc *fistarc;
};

void creatList(head *G,int n,int m){
    for(int i=0;i<n;i++){
        G[i].data=i+1;
        G[i].fistarc=NULL;
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        arc *p=new arc;
        p->data=b;
        p->nextarc=G[a-1].fistarc;
        G[a-1].fistarc=p;
    }
}

void BFS(head *G,int s,int n){
    bool visted[MAX_VERTEX_NUM];
    for(int i=0;i<MAX_VERTEX_NUM;i++){
        visted[i]=false;
    }
    queue<int> q;
    q.push(s);
    visted[s-1]=true;
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        cout<<temp<<" ";
        arc *p=G[temp-1].fistarc;
        while(p!=NULL){
            int t=p->data-1;
            if(!visted[t]){
                q.push(t);
                visted[t]=true;
            }
            p=p->nextarc;
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        if(!visted[i]){
            BFS(G,i,n);
        }
    }
}

void DFS(head *G,int s){
    bool visted[MAX_VERTEX_NUM];
    for(int i=0;i<MAX_VERTEX_NUM;i++){
        visted[i]=false;
    }
    cout<<s<<" ";
    visted[s]=true;
    arc *p=G[s-1].fistarc;
    while(p!=NULL){
        if(!visted[p->data]){
            DFS(G,p->data);
        }
    }
    cout<<endl;
    for(int i=0;i<MAX_VERTEX_NUM;i++){
        if(!visted[i]){
            DFS(G,i);
        }
    }
}

int main(){
    int N,M,S;
    cin>>N>>M>>S;
    head G[MAX_VERTEX_NUM];
    creatList(G,N,M);
    BFS(G,S,N);
    return 0;
}