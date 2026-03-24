#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const int MOD =1e9+7;

void test()
{
    int n=0;int m=0;int v=0;
    cin>>n>>m>>v;
    vector<vector<ll>>dp(v+1,vector<ll>(m+1));//前v价格恰好m体积的方案数
    dp[0][0]=1;
    vector<int>v1(n);
    for(int i=0;i<n;i++) cin>>v1[i];

    for(int i=0;i<n;i++){
        for(int j=v1[i];j<=v;j++){
            //dp[v1[i]][1]++;
            for(int x=1;x<=m;x++){
                //if(x*v1[i]<=v) dp[x*v1[i]][x]=1;
                dp[j][x]=(dp[j][x]+dp[j-v1[i]][x-1]+MOD)%MOD;
                //if(x==m) cout<<(dp[j-v1[i]][x])<<' '<<x<<" ";
            }
        }
    }
    ll ans=0;
    for(int i=0;i<=v;i++){
        ans=(ans+dp[i][m]+MOD)%MOD;
        //cout<<(dp[i][m])<<" ";
    }
    cout<<ans%MOD<<"\n";
}

int main()
{
    int t=1;
    cin>>t;
    while(t--) test();
    return 0;
}