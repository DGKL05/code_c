#include<bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

ll power(ll a,ll b){
    ll ans = 1;
    while(b){
        if(b&1) ans =  ans * a;
        a = a * a;
        b>>=1;
    }
    return ans;
}

void test()
{
    ll n=0;ll k=0;
    cin>>n>>k;
    // cout<<"pow = "<< power(500000000,3)<<" "<<pow(500000000,3)<<"\n";
    if(k > 31){
        cout<<"1\n";
        return ;
    }
    for(ll i = 0;;i++){
        if(power(i,k) > n){
            cout<<i-1<<"\n";
            return ;
        }
    }
    // cout<<ans<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}