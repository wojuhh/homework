#include<iostream>
#include<queue>
using namespace std;

struct Edge {
    int to;
    Edge* next;
};      // 邻接表

bool visited[100];      // 访问标记
Edge e[100];        // 邻接表

void BFS(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        Edge* p = e[u].next;
        while(p != NULL) {
            if(!visited[p->to]) {
                q.push(p->to);
                visited[p->to] = true;
            }
            p = p->next;
        }
    }
    cout << endl;
}       // 广度优先搜索

int main() {
    int N, M, S;
    cin >> N >> M >> S;
    for(int i = 0; i < N; i++) {
        e[i].next = NULL;
    }       // 初始化邻接表
    for(int i = 0; i < N; i++) {
        visited[i] = false;
    }       // 初始化访问标记
    for(int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;
        Edge* p = new Edge;     
        p->to = to;
        p->next = e[from].next;     
        e[from].next = p;       
        Edge* q = new Edge;
        q->to = from;
        q->next = e[to].next;
        e[to].next = q;
    }       // 构建邻接表
    BFS(S);     // 从S开始遍历
    for(int i = 1; i<= N; i++) {
        if(!visited[i]) {
            BFS(i);
        }
    }       // 遍历所有连通分量
    return 0;
}