#include<bits/stdc++.h>
using namespace std;
using ll =long long;

ll kuai_pow(ll a,ll b,ll m){
    ll ans=1;
    while(b){
        if(b&1)ans=(ans*a%m)%m;
        a=(a*a)%m;
        b>>=1;
    }
    return ans;
}

int main()
{
    //cout<<kuai_pow(9,9,100000000000);
    int t=0;
    cin>>t;
    while(t--){
        ll a=0;ll b=0; ll m=0;
        cin>>a>>b>>m;
        cout<<kuai_pow(a,b,m)<<"\n";
    }
    return 0;
}