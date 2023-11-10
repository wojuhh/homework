#include<iostream>
using namespace std;

int main(){
    char a[10000];
    char b[10000];
    cin.getline(a, 10000, '#');
    cin.getline(b, 10000, '#');
    int lena = 0;
    int lenb = 0;
    while(a[lena] != '\0') {
        lena++;
    }
    while(b[lenb] != '\0') {
        lenb++;
    }
    for(int i = 0; i < lena; i++) {
        b[lenb + i] = a[i];
    }
    b[lena + lenb] = '\0';
    cout << b << endl;
    return 0;
}