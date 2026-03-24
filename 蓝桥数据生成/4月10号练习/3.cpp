#include<bits/stdc++.h>
using namespace std;
using ll =long long;


int main()
{
    int n=0;int v=0;
    cin>>n>>v;
    vector<int>v1(n+1);
    vector<int>arr(n+1);
    for(int i=1;i<=n;i++) {
        cin>>v1[i]>>arr[i];
    }
    vector<vector<int>>dp(n+1,vector<int>(v+1,0));
    dp[0][0]=0;
    
    // for(int i=0;i<v1[0];i++) dp[0][i]=0;
    // for(int i=v1[0];i<=v;i++) dp[0][i]=arr[0];
    for(int i=1;i<=n;i++){
        for(int j=0;j<=v;j++){
            dp[i][j]=dp[i-1][j];
            if(j-v1[i]>=0) dp[i][j]=max(dp[i][j],dp[i-1][j-v1[i]]+arr[i]);
        }
    }
    cout<<dp[n][v]<<"\n";
    return 0;
}