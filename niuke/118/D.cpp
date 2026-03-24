#include<bits/stdc++.h>
using namespace std;
using ll =long long;

bool check(const vector<ll>& a, const vector<ll>& b, ll x) {
    for (int i = 0; i < a.size(); i++) {
        if (x < a[i]) return false;
        ll num = x - a[i];
        x = num + min(num, b[i]);
    }
    return true;
}

void test()
{
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    ll L = 0;
    ll R = 1e18;
    while (L < R) {
        ll mid = L + (R - L) / 2;
        if (check(a, b, mid)) {
            R = mid;
        } else {
            L = mid + 1;
        }
    }
    cout << L << '\n';
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}