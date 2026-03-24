#include<bits/stdc++.h>
using namespace std;
using ll =long long;

const ll MAX_LIMIT = 1000000000;

void test()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> idx(n + 1);
    idx[n] = n;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] != 1) {
            idx[i] = i;
        } else {
            idx[i] = idx[i + 1];
        }
    }
    unordered_set<ll> s1;
    for (int l = 0; l < n; l++) {
        ll cur = 1;
        int r = l;
        while (r < n) {
            if (cur * a[r] > MAX_LIMIT) {
                break;
            }
            if (a[r] == 1) {
                s1.insert(cur);
                r = idx[r];
            } else {
                cur = cur * a[r];
                s1.insert(cur);
                r++;
            }
        }
    }
    while (q--) {
        ll x;
        cin >> x;
        if (s1.find(x) != s1.end()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}