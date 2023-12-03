#include<iostream>
#include<algorithm>
using namespace std;

struct Edge{
    int v[100];
    int len;
};      // 邻接表

Edge e[100];        // 邻接表
bool visited[100];      // 访问标记

void DFS(int s){
    cout << s << " ";
    visited[s] = true;
    for(int i = 0; i < e[s].len; i++){
        if(!visited[e[s].v[i]]){
            DFS(e[s].v[i]);
        }
    }
}       // 深度优先搜索

int main(){
    int N, M, S;
    cin >> N >> M >> S;
    for(int i = 0; i < N; i++){
        e[i].len = 0;
    }       
    for(int i = 0; i < M; i++){
        int from, to;
        cin >> from >> to;
        e[from].v[e[from].len++] = to;
        e[to].v[e[to].len++] = from;
    }       // 构建邻接表
    for(int i = 0; i < 100; i++){
        visited[i] = false;
    }       // 初始化访问标记
    for(int i = 1;i <= N; i++){
        sort(e[i].v, e[i].v + e[i].len);
    }       // 邻接表排序
    DFS(S);     // 从S开始遍历
    cout << endl;
    for(int i = 1; i <= N; i++){
        if(!visited[i]){
            DFS(i);
            cout << endl;
        }
    }       // 遍历所有连通分量
    return 0;
}