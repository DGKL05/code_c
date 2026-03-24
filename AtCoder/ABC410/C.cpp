#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int q=0;
    cin>>n>>q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    ll num = 0;

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int p;
            ll x;
            cin >> p >> x;
            ll index = (num + p - 1) % n;
            if (index < 0) index += n;
            a[index] = x;
        } else if (op == 2) {
            int p;
            cin >> p;
            ll index = (num + p - 1) % n;
            if (index < 0) index += n;
            cout << a[index] << '\n';
        } else if (op == 3) {
            ll k;
            cin >> k;
            num = (num + k) % n;
            if (num < 0) num += n;
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}