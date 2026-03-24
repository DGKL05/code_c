#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int m=0;
    cin>>n>>m;
    vector<int>w(n,0);
    vector<int>q(n,0);
    vector<int>p(n,0);
    for(int i=0;i<n;i++){
        cin>>p[i]>>q[i]>>w[i];
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        ans += ( (m*p[i] + q[i] - 1)/q[i] - w[i] ) > 0 ? (m*p[i] + q[i] - 1)/q[i] - w[i] : 0;
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