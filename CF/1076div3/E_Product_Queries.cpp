#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;
    vector<int>dp(n+1,1e8);
    for(auto x:arr) dp[x] = 1;
    for(int j=1;j<=n;j++){
        for(int i=j;i<=n;i+=j){
            dp[i] = min(dp[i] , dp[j] + dp[i/j]);
        }
    }
    for(int i=1;i<=n;i++){
        if(dp[i] == 1e8) cout<<"-1 ";
        else cout<<dp[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}