#include<iostream>
using namespace std;
#define MAX_VERTEX_NUM 50
typedef struct adj {
    int data;
} adj;      //邻接矩阵

adj AdjNode[MAX_VERTEX_NUM][MAX_VERTEX_NUM];         
bool visited[MAX_VERTEX_NUM];       //记录是否访问过
int n;
int sum;    //记录连通分量个数

void DFS(int s) {
    visited[s] = true;
    for(int i = 0; i < n; i++) {
        if(AdjNode[s][i].data == 1 && !visited[i]) {
            DFS(i);
        }
    }
}       //深度优先搜索

void findConnectedComponents() {
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            DFS(i);
            sum++;
        }
    }
}       //寻找连通分量

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> AdjNode[i][j].data;
        }
    }
    findConnectedComponents();
    cout << sum << endl;
    return 0;
}