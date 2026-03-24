#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const int N = 1000;

ll dp[N][N];

int main()
{
    int n=0;int m=0;int q=0;
    cin>>n>>m>>q;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=1e18;

        }
    }
    
    for(int i=0;i<m;i++){
        int x=0;int y=0;ll w=0;
        cin>>x>>y>>w;
        dp[x][y]=min(w,dp[x][y]);
        dp[y][x]=min(w,dp[y][x]);
    }
    
    for(int i=1;i<=n;i++){
        dp[i][i]=0;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=min(dp[i][k]+dp[k][j],dp[i][j]);
            }
        }
    }
    for(int i=0;i<q;i++){
        int x=0;int y=0;
        cin>>x>>y;
        if(dp[x][y]!=1e18) cout<<(dp[x][y])<<"\n";
        else cout<<"-1\n";
    }
    return 0;
}