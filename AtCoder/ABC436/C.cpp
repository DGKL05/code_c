#include<bits/stdc++.h>
using namespace std;
using ll = long long;



void test()
{
    ll n=0;int m=0;
    cin>>n>>m;
    set<pair<ll,ll>>s1;
    int ans=0;
    while(m--){
        int x=0;int y=0;
        cin>>x>>y;
        if(s1.find({x,y}) != s1.end() || s1.find({x+1,y}) != s1.end() || s1.find({x,y+1}) != s1.end() || s1.find({x+1,y+1}) != s1.end()){

        }else{
            ans++;
            s1.insert(pair<ll,ll>(x,y));
            s1.insert(pair<ll,ll>(x+1,y));
            s1.insert(pair<ll,ll>(x,y+1));
            s1.insert(pair<ll,ll>(x+1,y+1));
        }
    }
    cout<<ans<<'\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T=1;
    // cin>>T;
    while(T--) test();
    return 0;
}