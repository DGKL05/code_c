#include<bits/stdc++.h>
using namespace std;
using ll =long long;

const ll INF = 0x3f3f3f3f3f3f3f3f;

struct node{
    int p;
    vector<int>v1;
};

void test()
{
    int n=0;int k=0;int sum=0;
    cin>>n>>k;
    vector<node>arr(n+1);
    vector<vector<ll>>dp(k+1,vector<ll>(2,-INF));
    arr[0] ={1,{0,0}};
    for(int i=1;i<=n;i++){
        int p1=0;
        cin>>p1;
        vector<int>temp(p1+1);
        for(int j=1;j<=p1;j++){
            cin>>temp[j];
        }
        sum+=p1;
        node a;a.p=p1;a.v1=temp;
        arr[i] = a;
    }
    
    if(sum<=k){
        ll ans=0;
        for(int i=1;i<=n;i++){
            auto x = arr[i];
            ans+=x.v1[x.p];
        }
        cout<<ans<<"\n";
        return ;
    }
    dp[0][0]=0;
    // dp[1][0]=0;
    for(int i=1;i<=n;i++){
        vector<vector<ll>> new_dp(k+1, vector<ll>(2, -INF));
        auto x = arr[i];
        for(int j=0;j<=k;j++){
            new_dp[j][0] = dp[j][0];
            new_dp[j][1] = dp[j][1];
            
            if(j>=x.p){
                new_dp[j][0] = max(new_dp[j][0], dp[j-x.p][0] + x.v1[x.p]);
                new_dp[j][1] = max(new_dp[j][1], dp[j-x.p][1] + x.v1[x.p]);
            }
            
            for(int l=1; l<=j && l<x.p; l++){ 
                new_dp[j][1] = max(new_dp[j][1], dp[j-l][0] + x.v1[l]);
            }
        }
        dp = (new_dp);
    }
    // for(int i=0;i<=k;i++){
    //     cout<<dp[i][0]<<" ";
    // }
    // cout<<"\n";
    cout<<max(dp[k][0],dp[k][1])<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}