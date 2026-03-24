#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n;
    cin >> n;
    vector<vector<int>> arrs;
    int max_len = 0;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        vector<int> a(k);
        for (int j = 0; j < k; j++) {
            cin >> a[j];
        }
        arrs.push_back(a);
        if (k > max_len) max_len = k;
    }
    sort(arrs.begin(), arrs.end());
    vector<int> lens;
    for (auto& a : arrs) {
        lens.push_back(a.size());
    }
    vector<int> ans;
    int ptr = 0;
    for (int j = 0; j < max_len; j++) {
        while (ptr < n && lens[ptr] <= j) {
            ptr++;
        }
        if (ptr < n) {
            ans.push_back(arrs[ptr][j]);
        } else {
            break;
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] <<" ";
    }
    cout << '\n';
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}