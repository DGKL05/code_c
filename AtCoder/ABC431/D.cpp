#include<bits/stdc++.h>
using namespace std;
using ll =long long;

struct node {
    ll w;
    ll h;
    ll b;
};

void test()
{
    int n=0;
    cin>>n;
    vector<node>arr;
    ll max_w=0;
    ll ans1=0;
    arr.push_back({0,0,0});
    for(int i=0;i<n;i++){
        ll w=0;ll h=0;ll b=0;
        cin>>w>>h>>b;
        max_w+=w;
        arr.push_back({w,h,b});
    }
    // cout<<"max_w = "<<max_w<<"\n";
    vector<ll>dp((max_w/2)+1,-1e18);
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        vector<ll>new_dp = dp;
        for(int j = 0 ; j<=max_w/2 ; j++){
            if (dp[j] == -1e18) continue;
            new_dp[j] = max(new_dp[j], dp[j] + arr[i].b);
            int temp = j + arr[i].w;
            if (temp <= max_w/2) {
                new_dp[temp] = max(new_dp[temp], dp[j] + arr[i].h);
            }
        }
        dp = move(new_dp);
    }
    ll ans=0;
    for(int i=0;i<= max_w/2;i++){
        // cout<<dp[i]<<"\n";
        ans = max(ans,dp[i]);
    }
    cout<<ans<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}