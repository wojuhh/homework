#include<iostream>
#include<string>
#include<vector>
using namespace std;

void getNext(int* next, const string& s) {
    int j = -1;
    next[0] = -1;
    for(int i = 1; i < s.size(); i++) {
        while(j >= 0 && s[i] != s[j+1]) {
            j = next[j];
        }
        if(s[i] == s[j+1]) {
            j++;
        }
        next[i] = j;
    }
}

int KMP(const string& s, const string& p) {
    int* next = new int[p.size()];
    getNext(next, p);
    int j = -1;
    for(int i = 0; i < s.size(); i++) {
        while(j >= 0 && s[i] != p[j+1]) {
            j = next[j];
        }
        if(s[i] == p[j+1]) {
            j++;
        }
        if(j == p.size() - 1) {
            delete[] next;
            return i - p.size() + 1;
        }
    }
    delete[] next;
    return -1;
}

int main() {
    string s, p;
    cin >> s >> p;
    cout << KMP(s, p) << endl;
    return 0;
}