#include<iostream>
using namespace std;

int mid_n[100];
int mid_n_index=0;   

void Search_Bin(int *a,int n,int key){
    int low=0,high=n-1;
    while(low<=high){
        int mid = (low+high)/2;
        mid_n[mid_n_index++]=a[mid];
        if(a[mid]==key){
            cout<<mid<<endl;
            return;
        }
        else if(a[mid]>key){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    cout<<"no"<<endl;
}

int main(){
    int n;
    cin>>n;
    int *a = new int[n];
    for(int i=0;i<n;i++){
        int key;
        cin>>key;
        char ch;
        ch = getchar();
        a[i]=key;
    }
    int key;
    cin>>key;
    Search_Bin(a,n,key);
    for(int i=0;i<mid_n_index-1;i++){
        cout<<mid_n[i]<<",";
    }
    cout<<mid_n[mid_n_index-1];
    return 0;
}