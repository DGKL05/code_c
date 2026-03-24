#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<int> v1(n);
    for(int i = 0; i < n; i++){
        int num=0;
        cin >> num;
        v1.push_back(num);
    }
    int num = 0, maxAns = v1[0];
    for (auto &x: v1) {
        num = max(num + x, x);
        maxAns = max(maxAns, num);
    }
    cout << maxAns << endl;
    return 0;
}