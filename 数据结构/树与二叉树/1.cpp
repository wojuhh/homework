#include<iostream>
#include<string>
using namespace std;

void build(string a,string b){
    if(b.size()==0) return;
    int n = b.size();
    char root = b[n-1];
    int pos=a.find(root);
    cout<<root;
    build(a.substr(0,pos),b.substr(0,pos));
    build(a.substr(pos+1),b.substr(pos,n-pos-1));
}      //根据中序和后序得到前序，递归

int main(){
    string a,b;
    cin>>a>>b;
    build(a,b);
    return 0;
}