#include<iostream>
#include<algorithm>
using namespace std;
#define INFINITY 65535
#define INT_MAX 65535
#define MAX_VERTEX_NUM 100

struct arc{
    int id;
    int weight;
}AdjList[MAX_VERTEX_NUM][MAX_VERTEX_NUM];       //邻接矩阵

void creatList(arc AdjList[][MAX_VERTEX_NUM],int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            AdjList[i][j].weight=INFINITY;
        }
    }
    for(int i=0;i<m;i++){
        int id,a,b,w;
        cin>>id>>a>>b>>w;
        AdjList[a][b].id=id;
        AdjList[a][b].weight=w;
    }
}       //创建邻接矩阵

void kruskal(arc AdjList[][MAX_VERTEX_NUM],int n,int m){
    int parent[MAX_VERTEX_NUM];     //并查集
    int rank[MAX_VERTEX_NUM];       //记录边的id 
    for(int i=0;i<n;i++){
        parent[i]=i;
        rank[i]=0;
    }       //初始化并查集
    int count=0;
    int sum=0;
    int p=0;
    while(count<n-1){
        int min=INT_MAX;
        int a=-1,b=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(AdjList[i][j].weight<min){
                    min=AdjList[i][j].weight;
                    a=i;
                    b=j;
                }
            }
        }
        int aRoot=a;
        int bRoot=b;
        while(aRoot!=parent[aRoot]){
            aRoot=parent[aRoot];
        }       //寻找a的根节点
        while(bRoot!=parent[bRoot]){
            bRoot=parent[bRoot];
        }       //寻找b的根节点
        if(aRoot!=bRoot){
            parent[aRoot]=bRoot;
            count++;
            sum+=min;
            rank[p]=AdjList[a][b].id;
            p++;
        }       //如果a和b不在同一个集合中，将a的根节点的父节点设为b的根节点
        AdjList[a][b].weight=INT_MAX;       //将a和b之间的边的权值设为无穷大，防止下次被选中
    }
    cout<<sum<<endl;
    sort(rank,rank+p);
    for(int i=0;i<p;i++){
        cout<<rank[i]<<" ";
    }
}       //克鲁斯卡尔算法

int main(){
    int n,e;
    cin>>n>>e;
    arc AdjList[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    creatList(AdjList,n,e);
    kruskal(AdjList,n,e);
    return 0;
}