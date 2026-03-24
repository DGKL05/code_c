#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    ll n=0;ll k=0;
    cin>>n>>k;
    if(n==1){
        cout<<1<<"\n";
        return ;
    }
    ll k1=k;
    ll ans=0;
    while(k && n!=1){
        ans++;
        n=(ll)sqrt(n);
        cout<<n<<"\n";
        --k;
    }
    // cout<<k<<"\n";
    if(k==0) cout<<2*k1+1<<"\n";
    else cout<<ans+1+k1<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test();
    return 0;
}