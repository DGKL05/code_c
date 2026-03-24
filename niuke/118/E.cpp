#include<bits/stdc++.h>
using namespace std;
using ll =long long;

const int MAX_N = 8000;
const int MAX_SUM = 8000;
const int mod = 998244353;

int dp[MAX_N + 1][MAX_SUM + 1] = {0};

void test()
{
    int n, m;
    cin >> n >> m;
    if (m < n) {
        cout << 0 << '\n';
    } else {
        int s = m - n;
        cout << dp[n][s] << '\n';
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    dp[0][0] = 1;
    for (int i = 1; i <= MAX_N; i++) {
        for (int j = 0; j <= MAX_SUM; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= i) {
                dp[i][j] = (dp[i][j] + dp[i][j - i]) % mod;
            }
        }
    }
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}