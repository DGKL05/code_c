#include<bits/stdc++.h>
using namespace std;
using ll =long long;
/*
    dp[i][j] 表示 抵达i时前一步通过走j+1步到达
    dp[i][0] = max( dp[i-1][1] + arr[i] , dp[i][0] );
    if(i-2 >= 0) dp[i][1] = max( dp[i-2][0] + arr[i] , dp[i-2][1] + arr[i] );
*/
void test()
{
    int n=0;
    cin>>n;
    vector<ll>arr(n+1,0);
    for(int i=0;i<n;i++){
        cin>>arr[i+1];
    }
    vector<vector<ll>>dp(n+1,vector<ll>(2,0));
    for(int i=1;i<=n;i++){
        dp[i][0] = max( dp[i-1][1] + arr[i] , dp[i][0] );
        if( i-2 >= 0) dp[i][1] = max( dp[i-2][0] + arr[i] , dp[i-2][1] + arr[i] );
    }
    cout << max(dp[n][0] , dp[n][1]) <<"\n";
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