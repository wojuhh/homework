#include<iostream>
using namespace std;

int Partition(int *a, int low, int high) {
	a[0] = a[low];
	int pivotkey = a[low];
	while (low < high) {
		while (low < high && a[high] >= pivotkey)--high;
		a[low] = a[high];
		while (low < high && a[low] <= pivotkey)++low;
		a[high] = a[low];
	}
	a[low] = a[0];
	return low;
}       //快速排序的划分算法

void Qsort(int* a, int low, int high) {
	if (low < high) {
		int pivotloc = Partition(a, low, high);
		Qsort(a, low, pivotloc - 1);
		Qsort(a, pivotloc + 1, high);
	}
}       		//快速排序

int main(){
    int n,k;
    cin>>n>>k;
    int *a=new int [n+1];
    for(int i=1;i<n+1;i++){
        cin>>a[i];
    }
    int low = 1;
	int high = n;
	Qsort(a, low, high);
    cout<<a[n-k+1];		//输出第k大的数
    return 0;
}