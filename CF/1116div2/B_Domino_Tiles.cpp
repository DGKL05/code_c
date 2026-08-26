#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 998244353;

int calc(string &s, int idx) {
    int n = s.size();
    int ans = 0;
    for (int i = 0; i <= 1; i++) {
        bool ok = true;
        int cur = i;
        for (int i = idx; i < n; i += 2) {
            if (s[i] != '?' && s[i] - '0' != cur) {
                ok = false;
                break;
            }
            cur ^= 1;
        }
        if (ok) ans++;
    }
    return ans;
}

void test() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll ans1 = calc(s, 0);
    ll ans2 = calc(s, 1);
    cout << ans1 * ans2 % MOD << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) test();
    return 0;
}