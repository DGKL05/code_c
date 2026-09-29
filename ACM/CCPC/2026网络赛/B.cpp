#include<bits/stdc++.h> 
 
using namespace std; 
using ll = long long; 
 
const ll INF = 4e18; 
 
void test(){ 
    vector<ll>a(6); 
    for(int i=0;i<6;i++) cin>>a[i]; 
 
    ll k; 
    cin>>k; 
 
    sort(a.begin(),a.end()); 
 
    vector<ll>b; 
    b.push_back(1); 
 
    for(int i=0;i<6;i++){ 
        b.push_back(a[i]+1); 
    } 
 
    sort(b.begin(),b.end()); 
    b.erase(unique(b.begin(),b.end()),b.end()); 
 
    vector<int>w(b.size()); 
 
    for(int i=0;i<b.size();i++){ 
        w[i] = lower_bound(a.begin(),a.end(),b[i])-a.begin(); 
    } 
 
    vector<vector<ll>>dp(7,vector<ll>(37,INF)); 
    vector<vector<int>>pre(7,vector<int>(37,-1)); 
    vector<vector<ll>>val(7,vector<ll>(37,-1)); 
 
    dp[0][0] = 0; 
 
    for(int i=0;i<6;i++){ 
        for(int j=0;j<=36;j++){ 
            if(dp[i][j] == INF) continue; 
 
            for(int t=0;t<b.size();t++){ 
                int nj = j+w[t]; 
 
                if(dp[i+1][nj] > dp[i][j]+b[t]){ 
                    dp[i+1][nj] = dp[i][j]+b[t]; 
                    pre[i+1][nj] = j; 
                    val[i+1][nj] = b[t]; 
                } 
            } 
        } 
    } 
 
    ll mn = INF; 
    int idx = -1; 
 
    for(int i=19;i<=36;i++){ 
        if(dp[6][i] < mn){ 
            mn = dp[6][i]; 
            idx = i; 
        } 
    } 
 
    if(mn > k){ 
        cout<<"NO\n"; 
        return; 
    } 
 
    vector<ll>ans; 
 
    for(int i=6;i>=1;i--){ 
        ans.push_back(val[i][idx]); 
        idx = pre[i][idx]; 
    } 
 
    reverse(ans.begin(),ans.end()); 
 
    ans[0] += k-mn; 
 
    cout<<"YES\n"; 
 
    for(int i=0;i<6;i++){ 
        cout<<ans[i]<<" "; 
    } 
    cout<<"\n"; 
} 
 
int main() 
{ 
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0); 
    int T = 1; 
    // cin>>T; 
    while(T--) test(); 
    return 0; 
}