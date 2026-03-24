#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 998244353;
const int N = 5 * 1e5 + 5;
ll ans[N];

void test()
{
    ll n = 0;
    cin >> n;
    cout << ans[n] << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    vector<ll> inv(N + 1);
    inv[1] = 1;
    for (int i = 2; i <= N; i++)
    {
        inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
    }

    vector<ll> fact(N + 1);
    fact[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        fact[i] = fact[i - 1] * i % MOD;
    }

    ll H = 0, H2 = 0, H3 = 0;
    for (int k = 1; k <= N; k++)
    {
        H = (H + inv[k]) % MOD;
        H2 = (H2 + inv[k] * inv[k]) % MOD;
        H3 = (H3 + inv[k] * inv[k] % MOD * inv[k]) % MOD;
        ll term1 = H;
        ll term2 = 3 * ((H * H % MOD - H2 + MOD) % MOD) % MOD;
        ll term3 = (H * H % MOD * H % MOD - 3 * H % MOD * H2 % MOD + 2 * H3 % MOD) % MOD;
        term3 = (term3 + MOD) % MOD;
        ll total = (term1 + term2 + term3) % MOD;
        ans[k] = fact[k] * total % MOD;
    }
    int T = 1;
    cin >> T;
    while (T--)
        test();
    return 0;
}