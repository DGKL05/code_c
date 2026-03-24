#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const int N=5*1e6+5;
void test()
{
    int n=0;ll x,y,z;ll temp=0;
    cin>>n>>x>>y>>z;

    vector<ll>v1(n+5);
    vector<ll>m1(n+1);
    ll x1=0;
    for(int i=0;i<n;i++) cin>>x1,m1[++v1[x1]]++;
    ll ans=1LL*x*m1[1];
    for(int i=2;i<=n;i++){
        ans+=max(y*m1[i],z+x*(m1[i])-x);
    }
    cout<<ans<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}