#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const int N = 1e3+5;
int v1[N];int w[N];ll dp[N];

int main()
{
    int n=0;int v;
    cin>>n>>v;
    for(int i=1;i<=n;i++) cin>>v1[i]>>w[i];
    dp[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=v;j>=v1[i];j--){
            dp[j]=dp[j];
            if(j-v1[i]>=0) dp[j]=max(dp[j],dp[j-v1[i]]+w[i]);
        }
    }
    cout<<dp[v];
}