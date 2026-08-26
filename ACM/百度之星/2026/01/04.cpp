#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1505;

ll b[N][N];
ll dp[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // 先直接把 A 存进 b
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            cin >> b[i][j];
        }
    }

    /*
        b[i][j] =
        sum_{l=1..i} sum_{r=j..n} A[l][r]
    */
    for (int i = 1; i <= n; i++) {
        for (int j = n; j >= i; j--) {
            b[i][j] +=
                b[i - 1][j]
                + b[i][j + 1]
                - b[i - 1][j + 1];
        }
    }

    /*
        原答案 =
        sum b[i][i]
        - 2 * 最大 b 权完美匹配
    */
    ll sum = 0;

    for (int i = 1; i <= n; i++) {
        sum += b[i][i];
    }

    /*
        长度为 2
    */
    for (int i = 1; i < n; i++) {
        dp[i][i + 1] = b[i][i + 1];
    }

    /*
        区间 DP
    */
    for (int len = 4; len <= n; len += 2) {

        for (int l = 1; l + len - 1 <= n; l++) {

            int r = l + len - 1;

            /*
                情况 1：
                l 和 r 匹配
            */
            dp[l][r] =
                dp[l + 1][r - 1]
                + b[l][r];

            /*
                情况 2：
                分割成两个偶数区间
            */
            for (
                int mid = l + 1;
                mid <= r - 2;
                mid += 2
            ) {

                dp[l][r] = max(
                    dp[l][r],
                    dp[l][mid]
                    + dp[mid + 1][r]
                );
            }
        }
    }

    cout << sum - 2LL * dp[1][n] << '\n';

    return 0;
}