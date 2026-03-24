#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    ll n=0;ll k=0;
    cin>>n>>k;
    ll ans=0;
    int idx=0;
    for(int i=n;ans<k;i++){
        ans+=i;
        idx++;
    }
    cout<<max(0,idx-1)<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}