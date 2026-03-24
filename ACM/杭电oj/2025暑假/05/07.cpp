#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const ll MOD=1e9+7;

ll power(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1) ans=(ans*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return ans;
}

void test()
{
    ll n=0;ll k=0;
    cin>>n>>k;
    ll k1=power(n-k+1,MOD-2);
    // cout<<"k1 = "<<k1<<"\n";
    cout<<(k%MOD*k1%MOD)%MOD<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}