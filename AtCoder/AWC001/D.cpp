#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const ll INF_NEG = -1LL * 1000000000000000000000000000000LL;
struct node{
    ll a;ll b;
};

void test()
{
    int n=0;int m=0;int k=0;ll ans = 0;
    cin>>n>>m>>k;
    vector<vector<ll>>dp(n+1,vector<ll>(m+1,INF_NEG));
    vector<node>arr(n+1);
    for(int i=1;i<=n;i++) cin>>arr[i].a>>arr[i].b;
     for (int i = 1; i <= n; ++i) {
        ll bi = arr[i].b;
        ll ai = arr[i].a;
        for (int c = bi; c <= m; ++c) {
            int r = c - bi;
            ll best = 0;
            for (int j = max(1, i - k); j < i; ++j) {
                best = max(dp[j][r] , best);
            }
            ll val = best + ai;
            dp[i][c] = val;
            ans = max(ans , val);
        }
    }
    cout<<ans<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}