#include<iostream>
using namespace std;

struct Treenode{
    int lhcild;
    int rhcild;
};     //树的结构体

int findroot(Treenode *tree,int n){
    int *hash=new int[n+1];
    for(int i=1;i<=n;i++){
        hash[i]=0;
    }
    for(int i=1;i<=n;i++){
        hash[tree[i].lhcild]=1;
        hash[tree[i].rhcild]=1;
    }
    for(int i=1;i<=n;i++){
        if(hash[i]==0){
            return i;
        }
    }
    return 0;
}       //找到根节点

void preorder(Treenode *tree,int root){
    if(root==0){
        return;
    }
    cout<<root<<" ";
    preorder(tree,tree[root].lhcild);
    preorder(tree,tree[root].rhcild);
}       //先序遍历

void inorder(Treenode *tree,int root){
    if(root==0){
        return;
    }
    inorder(tree,tree[root].lhcild);
    cout<<root<<" ";
    inorder(tree,tree[root].rhcild);
}       //中序遍历

void postorder(Treenode *tree,int root){
    if(root==0){
        return;
    }
    postorder(tree,tree[root].lhcild);
    postorder(tree,tree[root].rhcild);
    cout<<root<<" ";
}       //后序遍历

void levelorder(Treenode *tree,int root){
    if(root==0){
        return;
    }
    int *queue=new int[100];
    int front=0;
    int rear=0;
    queue[rear++]=root;
    while(front!=rear){
        int temp=queue[front++];
        cout<<temp<<" ";
        if(tree[temp].lhcild!=0){
            queue[rear++]=tree[temp].lhcild;
        }
        if(tree[temp].rhcild!=0){
            queue[rear++]=tree[temp].rhcild;
        }
    }
}       //层序遍历

int main(){
    int n;
    cin>>n;
    Treenode *tree=new Treenode[n+1];
    for(int i=1;i<=n;i++){
        cin>>tree[i].lhcild>>tree[i].rhcild;
    }
    int root=findroot(tree,n);
    preorder(tree,root);
    cout<<endl;
    inorder(tree,root);
    cout<<endl;
    postorder(tree,root);
    cout<<endl;
    levelorder(tree,root);
    cout<<endl;
    return 0;
}