#include <iostream>

using namespace std;

const int N = 7500 + 10;

int n, cnt;
int a[N], b[N];
int dp[N][N], ans[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= n; i ++) cin >> b[i];

    for (int i = 1; i <= n; i ++) 
        if (a[i] == b[i]) cnt ++;

    for (int i = 1; i <= n; i ++) {
        dp[i][i] = cnt;
        dp[i + 1][i] = cnt;
        ans[cnt] ++;
    }


    for (int len = 2; len <= n; len ++) {
        for (int i = 1; i <= n - len + 1; i ++) {
            int j = i + len - 1;
            dp[i][j] = dp[i + 1][j - 1] + (a[i] == b[j]) + (a[j] == b[i]) - (a[i] == b[i]) - (a[j] == b[j]);
            ans[dp[i][i + len - 1]] ++;
        }
    }

    for (int i = 0; i <= n; i ++) 
        cout << ans[i] << '\n';

    return 0;
}
