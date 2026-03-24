#include<bits/stdc++.h>
using namespace std;
using ll =long long;

struct node{
    ll zheng;
    ll xiao;
};

void test()
{
    int n=0;
    int k=0;
    cin>>n>>k;
    map<ll,vector<int>>m1;
    vector<node>arr(n);
    vector<bool>fa(n,false);
    for(int i=0;i<n;i++){
        cin>>arr[i].zheng>>arr[i].xiao;
        m1[arr[i].zheng - arr[i].xiao].push_back(i);
    }
    auto it = m1.end();
    it--;
    ll ans=0;
    while(k){
        for(auto x:it->second){
            if(k<=0) break;
            ans+=arr[x].xiao;
            k--;
            fa[x] = true;
        }
        it--;
    }
    for(int i=0;i<n;i++){
        if(!fa[i]) ans+=arr[i].zheng;
    }
    cout<<ans<<'\n';
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