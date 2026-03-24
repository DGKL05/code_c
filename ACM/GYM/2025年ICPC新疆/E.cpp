#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const int MOD = 1e9+7;
ll a1,b1,n;ll x=0;ll c;
ll power(ll a,ll b){
    long long ret=1;
    while(b) {
        if(b&1)ret=ret*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return ret;
}

void js()
{
    a1=(a1*(b1/c)+c+MOD)%MOD;
}
void test()
{
    cin>>a1>>b1>>n;
    c=__gcd(a1,b1);
    for(int i=0;i<n;i++){
        js();
    }
    cout<<a1<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}
