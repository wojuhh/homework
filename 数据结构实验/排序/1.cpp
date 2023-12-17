#include<iostream>
#include<algorithm>
using namespace std;
//作业的第三数据点有错误，代码以想不到的方式通过了，测试第三数据点确实有错误的的地方
void Ssq(int *a,int n,int s){
    for(int i=s/2;i>=0;i--){
        int least = i;
        int left = 2*i;
        int right = 2*i+1;
        if(left>n+1)continue;
        if(right>n+1){
            if(a[least]<a[left])swap(a[least],a[left]);
            else continue;
        }
        if(a[least]>min(a[left],a[right])){
            if(a[left] < a[right]){
                swap(a[least],a[left]);
            }else{
                swap(a[least],a[right]);
            }
        }else{
            continue;
        }
    }
}       // 从第i个节点开始heapify

int main(){
    int n;
    cin>>n;
    int *a=new int[n+1];
    for(int i=1;i<n+1;i++){
        cin>>a[i];
    }
    for(int i=n;i>=0;i--){
        Ssq(a,n,i);
        if(a[1]!=0)cout<<a[1]<<" ";
        swap(a[1],a[n+1]);
        n--;
    }       // 堆排序
    return 0;
}