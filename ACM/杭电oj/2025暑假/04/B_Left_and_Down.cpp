#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    ll a,b,k;
    cin>>a>>b>>k;
    ll a1=max(a,b);
    if(a1<=k){
        cout<<"1\n";
        return ;
    }
    ll g=__gcd(a,b);
    if(a/g<=k&&b/g<=k){
        cout<<"1\n";
        return ;
    }
    cout<<2<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}