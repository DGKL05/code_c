#include <bits/stdc++.h>
#define inf32 1e9
#define ls o << 1
#define rs o << 1 | 1

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned int;

const int N = 2e5 + 9;
const i64 inf64 = 2e18;

void solve()
{
    int n, m;std::cin >> n >> m;
    std::vector<i64> a(n);
    std::vector<bool> vis(n);
    std::vector<std::pair<i64, int>> c(n);

    for(auto &i : a) {
        std::cin >> i;
    }

    for(int i = 0;i < n;i ++) {
        c[i] = {a[i], i};
    }

    sort(c.begin(), c.end());

    for(int i = 1;i <= m;i ++) {
        int x;std::cin >> x;
        x --;
        vis[x] = true;
    }

    std::vector<std::array<i64, 2>> dp(n, {inf64, inf64});

    auto power = [](i64 x) -> i64 {
        return x * x;
    };

    dp[0][0] = 0;
    dp[1][1] = power(c[0].first - c[1].first);
    if(!vis[c[0].second])dp[1][0] = 0;

    for(int i = 2;i < n;i ++) {
        if(vis[c[i - 1].second]) {
            dp[i][0] = std::min(dp[i][0], dp[i - 1][1]);
            dp[i][1] = std::min(dp[i][1], dp[i - 1][0] + power(c[i - 1].first - c[i].first));
        } else {
            dp[i][0] = std::min(dp[i][0], std::min(dp[i - 1][0], dp[i - 1][1]));
            dp[i][1] = std::min(dp[i][1], dp[i - 1][0] + power(c[i - 1].first - c[i].first));
            dp[i][1] = std::min(dp[i][1], dp[i - 2][0] + power(c[i - 2].first - c[i].first));
        }
    }

    i64 ans = inf64;
    if(vis[c[n - 1].second])ans = std::min(ans, dp[n - 1][1]);
    else ans = std::min(ans, std::min(dp[n - 1][0], dp[n - 1][1]));

    std::cout << ans << '\n';
}
