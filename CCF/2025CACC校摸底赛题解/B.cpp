#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n = 0;
    cin>>n;
    int idx=1;
    ll p=1;
    ll ans=0;
    for(int i=1;i<=n;i++){
        ans+=p;
        p*=(++idx);
    }
    cout<<ans<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}