#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int m=0;float ans=0;
    cin>>n>>m;
    vector<ll>arr(n+1);arr[0]=0;
    for(int i=1;i<=n;i++) cin>>arr[i];
    sort(arr.begin(),arr.end());
    ll num = (n)/m;
    if(n%m!=0) num++;
    map<ll,vector<int>>m1;
    for(int i=1;i<=n-num+1;i++){
        vector<int>v1;
        for(int j=i;j<=n;j++){
            v1.push_back(j);
        }
        m1.insert(pair<ll,vector<int>>((arr[i+num-1]-arr[i]),v1));
    }
    set<int>idx;
    for(auto [l,r] : m1){
        for(auto x:r) if(idx.find(x) != idx.end()) continue;
        ans+=l;
        for(auto x:r) idx.insert(x);
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