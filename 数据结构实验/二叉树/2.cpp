#include<iostream>
#include<string>
#include<queue>
using namespace std;

struct Node{
    string data;
    Node *lchild, *rchild;
};

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
}

void levelOrder(Node *root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node *now = q.front();
        q.pop();
        cout << now->data;
        if(now->lchild != NULL){
            q.push(now->lchild);
        }
        if(now->rchild != NULL){
            q.push(now->rchild);
        }
    }
}

int main(){
    string tree;
    cin >> tree;
    int i = 0;
    Node *root = create(tree, i);
    levelOrder(root);
    return 0;
}