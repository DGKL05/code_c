#include <iostream>
#include <vector>
using namespace std;

const int mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        ll k;  
        cin >> n >> k;
        vector<int> s(n);
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }

        long long dp0 = 1, dp1 = 0, dpm1 = 0;
        for (int i = 0; i < n; i++) {
            long long new_dp0 = 0, new_dp1 = 0, new_dpm1 = 0;

            new_dp0 = (new_dp0 + dp0) % mod;  // choosing 0
            if (s[i] == 1) {
                new_dp1 = (new_dp1 + dp0) % mod;  // choosing k
            } else {
                new_dpm1 = (new_dpm1 + dp0) % mod;  // choosing k
            }

            if (s[i] == 1) {
                new_dp1 = (new_dp1 + dp1) % mod;
            } else {
                new_dp0 = (new_dp0 + dp1) % mod;
            }

            if (s[i] == 1) {
                new_dp0 = (new_dp0 + dpm1) % mod;
            } else {
                new_dpm1 = (new_dpm1 + dpm1) % mod;
            }

            dp0 = new_dp0;
            dp1 = new_dp1;
            dpm1 = new_dpm1;
        }

        cout << dp0 % mod << '\n';
    }
    return 0;
}