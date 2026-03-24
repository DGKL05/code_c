#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, int>> req;
    for (int i = 0; i < n; i++) {
        ll a;
        int b;
        cin >> a >> b;
        req.push_back({a, b});
    }
    ll ans = 0;
    ll d0 = req[0].first;
    int r0 = (req[0].second != 0) ? 1 : 0;
    if (d0 % 2 == r0) {
        ans += d0;
    } else {
        ans += d0 - 1;
    }
    for (int i = 0; i < n - 1; i++) {
        ll d = req[i+1].first - req[i].first;
        int r = (req[i].second != req[i+1].second) ? 1 : 0;
        if (d % 2 == r) {
            ans += d;
        } else {
            ans += d - 1;
        }
    }
    ans += m - req.back().first;
    cout << ans << '\n';
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}