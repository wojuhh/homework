#include<iostream>
#include<string>
using namespace std;

struct Node{
    string data;
    Node *lchild, *rchild;
};      //二叉树的结点

Node* create(string tree, int &i){
    Node *root = NULL;
    if(tree[i] == '#'){
        i++;
        return NULL;
    }
    else{
        root = new Node;
        root->data = tree[i];
        i++;
        root->lchild = create(tree, i);
        root->rchild = create(tree, i);
    }
    return root;   
}       //创建二叉树

void preOrder(Node *root){
    if(root){
        cout << root->data;
        preOrder(root->lchild);
        preOrder(root->rchild);
    }
}       //先序遍历

void inOrder(Node *root){
    if(root){
        inOrder(root->lchild);
        cout << root->data;
        inOrder(root->rchild);
    }
}       //中序遍历

void postOrder(Node *root){
    if(root){
        postOrder(root->lchild);
        postOrder(root ->rchild);
        cout << root->data;
    }
}       //后序遍历

int leafNum(Node *root){
    if(root == NULL)return 0;
    if(root->lchild == NULL && root->rchild == NULL)return 1;
    return leafNum(root->lchild) + leafNum(root->rchild);
}       //求叶子结点个数

int main(){
    string tree;
    cin >> tree; 
    int i = 0;
    Node *root = create(tree, i);
    preOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;
    cout << leafNum(root) << endl;
    return 0;
}