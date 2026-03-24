#include<bits/stdc++.h>
using namespace std;
using ll =long long;

ll lcm(ll a,ll b){
    ll g = 1LL*__gcd(a,b);
    return (a/g)*b;
}

void test()
{
    int n=0;int m=0;int q=0;
    cin>>n>>m>>q;
    vector<vector<ll>>arr(n+1);
    for(int i=0;i<m;i++){
        int x=0;int y=0;int g=0;
        cin>>x>>y>>g;
        arr[x].push_back(g);
        arr[y].push_back(g);
    }
    vector<ll>ans(n+1,1);
    for(int i=1;i<=n;i++){
        for(auto x:arr[i]) ans[i] = lcm(ans[i],x);
    }
    while(q--){
        int x=0;int y=0;
        cin>>x>>y;
        cout<<__gcd(ans[x] , ans[y])<<"\n";
    }
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