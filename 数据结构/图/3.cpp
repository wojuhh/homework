#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

unordered_map<string, unordered_map<string, int>> graph;
unordered_set<string> visited;
vector<string> res;

void DFS(string start, string end) {
    if(start == end) {
        res.push_back(start);
        return;
    }
    visited.insert(start);
    for(auto& neighbor : graph[start]) {
        if(visited.find(neighbor.first) == visited.end()) {
            DFS(neighbor.first, end);
        }
    }
}

int main(){
    int n;
    string end;
    cin >> n >> end;
    for(int i = 0; i < n; i++) {
        string node, neighbors;
        cin >> node;
        getline(cin, neighbors);
        node = node.substr(0, node.size() - 1);
        neighbors = neighbors.substr(1, neighbors.size() - 1);
        string neighbor;
        int cnt = 0;
        for(int j = 0; j < neighbors.size(); j++) {
            if(neighbors[j] == ',' || neighbors[j] == ':') {
                string name = neighbor.substr(cnt, neighbor.find(':'));
                graph[node][name] = 1;
                neighbor = "";
            } else {
                neighbor += neighbors[j];
            }
        }
    }
    for(auto& node : graph) {
        if(node.first != end) {
            visited.clear();
            DFS(node.first, end);
        }
    }
    sort(res.begin(), res.end());
    if(res.empty()) {
        cout << "None" << endl;
    } else {
        for(auto& node : res) {
            cout << node << " ";
        }
        cout << endl;
    }
    return 0;
}