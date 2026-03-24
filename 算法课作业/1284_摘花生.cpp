#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int m=0;
    cin>>n>>m;
    vector<vector<int>>arr(n+1,vector<int>(m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
        }
    }
    vector<vector<int>>dp(n+1,vector<int>(m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j] = max({dp[i][j] , dp[i-1][j] + arr[i][j] , dp[i][j-1] + arr[i][j]});
        }
    }
    cout<<dp[n][m]<<"\n";

}

int main()
{
    std::ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}