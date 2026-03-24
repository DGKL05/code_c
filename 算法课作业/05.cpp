#include <bits/stdc++.h>
using namespace std;
void inc(vector<int>& b) {
    for (int i = 0; i < b.size(); i++) {
        if (b[i]) {
            b[i] = 0;
        } else {
            b[i] = 1;
            break;
        }
    }
}

void PSet(vector<int>& a, vector<int>& b) {
    int n = a.size();
    int pw = pow(2, n);
    for (int i = 0; i < pw; i++) {
        cout << "{";
        for (int k = 0; k < n; k++) {
            if (b[k]) {
                cout << a[k];
            }
        }
        cout << "} ";
        inc(b);
    }
}

int main() {
    int n = 3;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n, 0); 
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    PSet(a, b);
    return 0;
}