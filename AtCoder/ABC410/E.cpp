#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX_N = 3005;
const int MAX_M = 3005;

ll dp[MAX_N][MAX_M];

void test() {
    int n;
    cin >> n;
    ll H, M;
    cin >> H >> M;
    vector<ll> A(n), B(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i] >> B[i];
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= M; j++) {
            dp[i][j] = -1;
        }
    }
    dp[0][M] = H;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= M; j++) {
            if (dp[i][j] < 0) continue; 
            if (dp[i][j] >= A[i]) {
                dp[i+1][j]=max(dp[i+1][j],dp[i][j]-A[i]);
            }
            if (j >= B[i]) {
                dp[i+1][j-B[i]]=max(dp[i][j],dp[i+1][j-B[i]]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= M; j++) {
            if (dp[i][j] >= 0) {
                ans = i; 
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    // cin>>T;
    while (T--) {
        test();
    }
    return 0;
}