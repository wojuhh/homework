#include<iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};      // 二叉树节点的定义

int dfsHeight(TreeNode* root) {
    if (root == NULL) return 0;
                
    int leftHeight = dfsHeight(root->left);
    if (leftHeight == -1) return -1;
    int rightHeight = dfsHeight(root->right);
    if (rightHeight == -1) return -1;
    
    if (abs(leftHeight - rightHeight) > 1)  return -1;
    return max(leftHeight, rightHeight) + 1;
}       // 深度优先搜索

bool isBalanced(TreeNode* root) {
    return dfsHeight(root) != -1;
}       // 判断是否为平衡二叉树

TreeNode* buildTree(vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "None") return nullptr;
    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);
    for (int i = 1; i < nodes.size(); i++) {
        TreeNode* parent = q.front();
        if (i % 2 == 1) {
            if (nodes[i] != "None") {
                parent->left = new TreeNode(stoi(nodes[i]));
                q.push(parent->left);
            }
        } else {
            if (nodes[i] != "None") {
                parent->right = new TreeNode(stoi(nodes[i]));
                q.push(parent->right);
            }
            q.pop();
        }
    }
    return root;
}       // 根据输入的vector建立二叉树

int main(){
    string s;
    getline(cin, s);        // 读取输入
    vector<string> nodes;
    int start = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            nodes.push_back(s.substr(start, i - start));
            start = i + 1;
        }
    }       // 读取输入
    nodes.push_back(s.substr(start, s.size() - start));     
    TreeNode* root = buildTree(nodes);      // 建立二叉树
    if (isBalanced(root)) cout << "True" << endl;
    else cout << "False" << endl;
    return 0;
}