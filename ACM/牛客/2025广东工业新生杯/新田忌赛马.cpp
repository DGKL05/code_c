#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void test()
{
    int n=0;int m=0;
    cin>>n>>m;
    int j=0;
    vector<ll>v1(n),v2(m);
    for(auto &x:v1) cin>>x;
    for(auto &x:v2) cin>>x;
    ll ans=0;
    for(int i=0;i<n&&j<m;i++){
        while(v2[j] >= v1[i] && j<m){
            j++;
        }
        if(j>=m) break;
        // cout<<v2[j]<<" "<<ans<<"\n";
        ans+=v2[j];
        j++;
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