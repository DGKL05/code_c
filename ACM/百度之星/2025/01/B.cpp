#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    ll l,r;
    cin>>l>>r;
	if(l==r && l==1){
        cout<<0<<"\n";
        return ;
    }
    if(l == r){
        cout<<"infty\n";
        return ;
    }
    ll ans=0;
    if(((l-1)%(r-l))==0){
        ll n=(l-1)/(r-l);
        n++;
        ans=1LL*(n-1)*n*(r-l)/2;
    }else{
        ll a1=((l-1)%(r-l));
        ll n=(l-1-a1)/(r-l);
        n++;
        ans=1LL*(n-1)*n*(r-l)/2+1LL*n*a1;
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