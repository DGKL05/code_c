#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    vector<vector<int>> dp(m, vector<int>(n));
    for(int &x:dp[0]){
        x=1;
    }
    
    for (int i = 0; i < m; i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    cout << dp[m - 1][n - 1] << "\n";

    return 0;
}