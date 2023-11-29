#include<iostream>
#include<stack>
using namespace std;

struct ArcNode{
    int adjvex;
    ArcNode *nextarc;
};      //邻接表

struct VNode{
    int data;
    ArcNode *firstarc;
};      //顶点表

void creatList(VNode *G,int n,int m){
    for(int i=0;i<n;i++){
        G[i].data=i+1;
        G[i].firstarc=NULL;
    }       
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        ArcNode *p=new ArcNode;
        p->adjvex=a;
        p->nextarc=G[b-1].firstarc;
        G[b-1].firstarc=p;
    }
}       //创建邻接表

void TopologicalOrder(VNode *G,int n){
    int *indegree=new int[n];
    for(int i=0;i<n;i++){
        indegree[i]=0;
    }       //初始化入度
    for(int i=0;i<n;i++){
        ArcNode *p=G[i].firstarc;
        while(p!=NULL){
            indegree[p->adjvex-1]++;
            p=p->nextarc;
        }
    }       //计算入度
    stack<int> s;
    int *ve =new int[n];        //ve数组
    for(int i=0;i<n;i++){
        ve[i]=1;
    }       //初始化ve
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            s.push(i);
        }
    }       //将入度为0的点入栈
    while(!s.empty()){
        int temp=s.top();    //取出栈顶元素
        s.pop();
        ArcNode *p=G[temp].firstarc;
        while(p!=NULL){
            indegree[p->adjvex-1]--;        //将temp的邻接点入度减一
            if(indegree[p->adjvex-1]==0){
                s.push(p->adjvex-1);
            }       
            if(ve[temp]+1>ve[p->adjvex-1]){
                ve[p->adjvex-1]=ve[temp]+1;
            }       //更新ve
            p=p->nextarc;
        }       //将temp的邻接点入度减一，如果入度为0，入栈
    }     
    int temp=0;
    for(int i=0;i<n;i++){
        if(ve[i]>temp){
            temp=ve[i];
        }
    }       //找到ve中的最大值
    cout<<temp<<endl;
}       //拓扑排序

int main(){
    int n,m;    
    cin>>n>>m;
    VNode *G=new VNode[n];
    creatList(G,n,m);
    TopologicalOrder(G,n);
    return 0;
}