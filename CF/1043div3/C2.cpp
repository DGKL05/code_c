#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const int MAX_POW = 65;
__int128 pow3[MAX_POW + 1];
void test()
{
    precompute_pow3();
    ll n, k;
    cin >> n >> k;
    vector<int> d(MAX_POW, 0);
    ll temp = n;
    int i_index = 0;
    while (temp) {
        d[i_index] = temp % 3;
        temp /= 3;
        i_index++;
    }
    int min_k = 0;
    for (int i = 0; i < MAX_POW; i++) {
        min_k += d[i];
    }
    if (k < min_k) {
        cout << -1 << '\n';
        continue;
    }
    ll cost0 = 0;
    for (int i = 0; i < MAX_POW; i++) {
        if (d[i] == 0) continue;
        if (i == 0) {
            cost0 += (ll) d[i] * 3;
        } else {
            ll term1 = pow3[i + 1];
            ll term2 = (ll)i * pow3[i - 1];
            cost0 += (ll) d[i] * (term1 + term2);
        }
    }
    vector<ll> cnt(MAX_POW, 0);
    for (int i = 0; i < MAX_POW; i++) {
        cnt[i] = d[i];
    }
    ll available_splits = (k - min_k) / 2;
    ll reduction = 0;
    for (int i = MAX_POW - 1; i >= 1; i--) {
        if (available_splits <= 0) break;
        if (cnt[i] > 0) {
            ll x = min(available_splits, cnt[i]);
            reduction += (ll)x * pow3[i - 1];
            available_splits -= x;
            cnt[i] -= x;
            cnt[i - 1] += 3 * x;
        }
    }
    ll ans = cost0 - reduction;
    cout<<ans<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    pow3[0] = 1;
    for (int i = 1; i <= MAX_POW; i++) {
        pow3[i] = pow3[i - 1] * 3;
    }
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}