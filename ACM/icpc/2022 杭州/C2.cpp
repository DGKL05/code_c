#include<bits/stdc++.h>
using namespace std;
using ll =long long;

const int inf = 0x3f3f3f3f;
const int N = 3e3 + 5;
int dp[N][N][2];

struct node{
    int p;
    vector<int>v1;
};

void test()
{
    int n=0;int k=0;int sum=0;
    cin>>n>>k;
    vector<node>arr(n+1);
    vector<int>temp;
    // arr[0] ={1,{0,0}};
    for(int i=1;i<=n;i++){
        int p1=0;
        cin>>p1;
        temp.resize(p1+1);
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
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            dp[i][j][0] = -inf;
            dp[i][j][1] = -inf;
        }
    }
    dp[0][0][0]=0;
    // dp[1][0]=0;
    for(int i=1;i<=n;i++){
        auto x = arr[i];
        for(int j=0;j<=k;j++){
            dp[i][j][0] = dp[i-1][j][0];
            dp[i][j][1] = dp[i-1][j][1];
            if(j>=x.p){
                dp[i][j][0] = max( dp[i][j][0] , dp[i-1][j-x.p][0] + x.v1[x.p]);
                dp[i][j][1] = max( dp[i][j][1] , dp[i-1][j-x.p][1] + x.v1[x.p]);
            }
            
            for(int l=1; l<=j && l<x.p; l++){ 
                 dp[i][j][1] = max( dp[i][j][1] , dp[i-1][j-l][0] + x.v1[l]);
            }
        }
    }
    cout<<max(dp[n][k][0],dp[n][k][1])<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}