#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    vector<vector<int>>pos(n+1);
    vector<int>p(n+1);
    vector<int>dp(n+1,0);
    vector<int>v1(n+1);
    for(int i=1;i<=n;i++){
        cin>>v1[i];
        p[i]=pos[v1[i]].size();
        pos[v1[i]].push_back(i);
    }
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1];
        if(p[i]+1 >= v1[i]){
            dp[i]=max(dp[i],v1[i]+ dp[pos[v1[i]][p[i] - v1[i] +1] -1 ]);
        }
    }
    cout<<dp[n]<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}