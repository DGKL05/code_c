#include<bits/stdc++.h>
using namespace std;
using ll =long long;
/*
5 10 15
-5 0 5
-2 -3 2
1 2 1
*/
const ll mod = 998244353;
ll f(vector<ll> &X, ll v) {
    int n = X.size();
    auto it = upper_bound(X.begin(), X.end(), v);
    int k = it - X.begin();
    int i = 0, j = 0;
    int idx = 0;
    ll cost = 0;
    while (i < k && j < n - k) {
        ll left_val = v - X[k - 1 - i];
        ll right_val = X[k + j] - v;
        if (left_val <= right_val) {
            cost += left_val * (2LL * idx - n + 1);
            i++;
            idx++;
        } else {
            cost += right_val * (2LL * idx - n + 1);
            j++;
            idx++;
        }
    }
    while (i < k) {
        ll left_val = v - X[k - 1 - i];
        cost += left_val * (2LL * idx - n + 1);
        i++;
        idx++;
    }
    while (j < n - k) {
        ll right_val = X[k + j] - v;
        cost += right_val * (2LL * idx - n + 1);
        j++;
        idx++;
    }
    return cost;
}


void test()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    ll cost0 = 0;
    for (int i = 0; i < n; i++) {
        cost0 += a[i] * (2LL * i - n + 1);
    }

    if (n == 1) {
        cout << (cost0 % mod + mod) % mod << "\n";
        return ;
    }

    ll maxa = a.back();
    ll l = 0, r = maxa;
    ll cost1 = 1e18;
    ll best_v1 = -1;

    for (int iter = 0; iter < 100; iter++) {
        if (r - l < 3) {
            for (ll v1 = l; v1 <= r; v1++) {
                ll f1 = f(a, v1);
                if (f1 < cost1) {
                    cost1 = f1;
                    best_v1 = v1;
                }
            }
            break;
        }
        ll m1 = l + (r - l) / 3;
        ll m2 = r - (r - l) / 3;
        ll f1 = f(a, m1);
        ll f2 = f(a, m2);
        if (f1 < cost1) {
            cost1 = f1;
            best_v1 = m1;
        }
        if (f2 < cost1) {
            cost1 = f2;
            best_v1 = m2;
        }
        if (f1 < f2) {
            r = m2;
        } else {
            l = m1;
        }
    }

    set<ll> s1;
    for (ll v1 = best_v1 - 10; v1 <= best_v1 + 10; v1++) {
        if (v1 < 0) continue;
        s1.insert(v1);
    }

    ll cost2 = 1e18;
    for (ll v1 : s1) {
        vector<ll> B;
        for (int i = 0; i < n; i++) {
            B.push_back(abs(a[i] - v1));
        }
        sort(B.begin(), B.end());
        ll l2 = 0, r2 = B.back();
        if (r2 < 0) r2 = 0;
        ll best_inner = 1e18;
        for (int iter2 = 0; iter2 < 100; iter2++) {
            if (r2 - l2 < 3) {
                for (ll v2 = l2; v2 <= r2; v2++) {
                    ll f_inner = f(B, v2);
                    if (f_inner < best_inner) best_inner = f_inner;
                }
                break;
            }
            ll m1 = l2 + (r2 - l2) / 3;
            ll m2 = r2 - (r2 - l2) / 3;
            ll f1_inner = f(B, m1);
            ll f2_inner = f(B, m2);
            if (f1_inner < best_inner) best_inner = f1_inner;
            if (f2_inner < best_inner) best_inner = f2_inner;
            if (f1_inner < f2_inner) {
                r2 = m2;
            } else {
                l2 = m1;
            }
        }
        if (best_inner < cost2) {
            cost2 = best_inner;
        }
    }

    ll ans = min(cost0, min(cost1, cost2));
    ans %= mod;
    if (ans < 0) {
        ans = (ans % mod + mod) % mod;
    }
    cout << ans << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}