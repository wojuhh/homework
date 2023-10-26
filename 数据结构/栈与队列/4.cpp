#include<iostream>
using namespace std;

int cir(int n, int m){
    if(n == 1) return 0;
    return (cir(n-1,m)+m)%n;
}   //递归, 从1开始数, 每次数m个, 最后剩下的数的下标(从0开始)(约瑟夫环)

int main(){
    int n;
    int m;
    cin >> n >> m;
    cout << cir(n,m)+1 << endl;
    return 0;
}