#include <iostream>
using namespace std;

int flag = 0;

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
}

void Qsort(int* a, int low, int high) {
	if (low < high) {
		int pivotloc = Partition(a, low, high);
		if (flag == 0) {
			cout << pivotloc << " ";
			flag = 1;
		}
		Qsort(a, low, pivotloc - 1);
		Qsort(a, pivotloc + 1, high);
	}
    if(low==1 && high==1){
        cout << 1 <<" ";
    }
}

int main()
{
	int n;
	cin >> n;
	int* a = new int[n+1];
	for (int i = 1; i < n+1; i++) {
		cin >> a[i];
	}
	int low = 1;
	int high = n;
	Qsort(a, low, high);
	for (int i = 1; i < n + 1; i++) {
		cout << a[i] << " ";
	}
    return 0;
}