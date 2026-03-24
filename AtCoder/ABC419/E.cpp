#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int N, M, L;
    cin >> N >> M >> L;
    vector<int> v1(N);
    for (int i = 0; i < N; i++) {
        cin >> v1[i];
    }

    vector<vector<int>> g(L);
    for (int i = 0; i < N; i++) {
        g[i % L].push_back(v1[i]);
    }

    vector<vector<ll>> cost(L, vector<ll>(M, 0));

    for (int r = 0; r < L; r++) {
        vector<int>& B = g[r];
        int k = B.size();
        if (k == 0) {
            for (int x = 0; x < M; x++) {
                cost[r][x] = 0;
            }
            continue;
        }

        sort(B.begin(), B.end());
        long long sum = 0;
        for (int num : B) {
            sum += num;
        }

        for (int x = 0; x < M; x++) {
            int p = upper_bound(B.begin(), B.end(), x) - B.begin();
            cost[r][x] = 1LL*x * k + (k - p) * M - sum;
        }
    }

    vector<ll> dp(M, LLONG_MAX);
    dp[0] = 0;

    for (int r = 0; r < L; r++) {
        vector<ll> new_dp(M, LLONG_MAX);
        for (int s = 0; s < M; s++) {
            if (dp[s] == LLONG_MAX) continue;
            for (int x = 0; x < M; x++) {
                int new_s = (s + x) % M;
                ll new_cost = dp[s] + cost[r][x];
                new_dp[new_s]=min(new_dp[new_s],new_cost);
            }
        }
        dp = new_dp;
    }

    cout << dp[0] << endl;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}