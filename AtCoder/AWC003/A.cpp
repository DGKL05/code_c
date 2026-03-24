#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;ll k=0;
    cin>>n>>k;
    int ans=0;
    for(int i=0;i<n;i++){
        ll a=0;ll b=0;
        cin>>a>>b;
        if(1LL*a*b >= k) ans++;
    }
    cout<<ans<<"\n";
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