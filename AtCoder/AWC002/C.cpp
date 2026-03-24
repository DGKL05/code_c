#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;ll m=0;
    cin>>n>>m;
    vector<ll>a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        if(a[i] >= m) continue;
        int temp = 0;
        if((m - a[i]) % b[i] != 0) temp++;
        // cout<<a[i] << " "<<b[i] <<" "<<(m - a[i]) / b[i]<<"\n";
        ans = max( ans , 1LL*(1LL*(m - a[i]) / b[i] + temp));
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