#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char x) : val(x), left(NULL), right(NULL) {}
};      // 二叉树的结点定义

TreeNode* buildTree(vector<char>& preorder, vector<char>& inorder) {
    if(preorder.empty()) return NULL;       // 递归出口
    TreeNode* root = new TreeNode(preorder[0]);
    int i = 0;
    for(; i < inorder.size(); i++) {
        if(inorder[i] == preorder[0]) break;
    }       // 找到根结点在中序遍历中的位置
    vector<char> left_pre(preorder.begin()+1, preorder.begin()+i+1);        
    vector<char> left_in(inorder.begin(), inorder.begin()+i);
    vector<char> right_pre(preorder.begin()+i+1, preorder.end());
    vector<char> right_in(inorder.begin()+i+1, inorder.end());
    root->left = buildTree(left_pre, left_in);      // 递归构建左子树
    root->right = buildTree(right_pre, right_in);       // 递归构建右子树
    return root;
}       // 根据前序遍历和中序遍历构建二叉树

bool isCompleteTree(TreeNode* root){
    if(root == NULL) return true;
    vector<TreeNode*> queue;
    queue.push_back(root);
    int i = 0;
    while(i < queue.size()){
        if(queue[i] == NULL) break;
        queue.push_back(queue[i]->left);
        queue.push_back(queue[i]->right);
        i++;
    }       // 层次遍历二叉树
    while(i < queue.size()){
        if(queue[i] != NULL) return false;
        i++;
    }
    return true;
}       // 判断二叉树是否为完全二叉树

int main() {
    vector<char> preorder;
    vector<char> inorder;
    char c;
    int temp;
    cin >> temp;
    preorder.push_back(temp+'0');
    while(c=getchar()!='\n'){
        cin >> temp;
        preorder.push_back(temp+'0');
    }
    cin >> temp;
    inorder.push_back(temp+'0');
    while(c=getchar()!='\n'){
        cin >> temp;
        inorder.push_back(temp+'0');
    }
    TreeNode* root = buildTree(preorder, inorder);
    cout << (isCompleteTree(root) ? "True" : "False") << endl;
    return 0;
}