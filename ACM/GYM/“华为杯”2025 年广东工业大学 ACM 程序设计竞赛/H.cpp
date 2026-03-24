#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    string s1;
    cin>>s1;
    int ans1=0;int ans0=0;
    vector<ll>sum(n);
    if(s1[0]=='1') sum[0]=1;
    else sum[0]=-1;
    for(int i=0;i<n;i++){
        if(s1[i]=='0') ans0++;
        else ans1++;
        if(i) {
            sum[i]=(ans1-ans0);
        }
    }
    ll ans=-1e18;
    for(int i=0;i<n-1;i++){
        ans=max(ans,1LL*(ll)(sum[i]*(sum[n-1]-sum[i])));
    }
    cout<<ans<<'\n';
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}