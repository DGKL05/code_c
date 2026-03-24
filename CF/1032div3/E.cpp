#include<bits/stdc++.h>
using namespace std;
using ll =long long;
ll l=0;ll r=0;
ll power(ll num)
{
    ll ans=0;ll idx=0;
    while(num){
        if(!(l&1) && !(r&1)){
            ans++;
        }else if((l&1) && (r&1)){
            ans++;
        }
        num>>=1;
    }
    return ans;
}
void test()
{
    cin>>l>>r;
    ll num=min(l,r);
    cout<<power(num)<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}