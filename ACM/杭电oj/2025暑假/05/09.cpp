#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    vector<int>a(n),b(n);
    vector<bool>fa(n-1,false);
    for(auto &x:a) cin>>x;
    for(auto &x:b) cin>>x;
    set<pair<int,int>>l,r;
    if(n==1){
        cout<<"1\n";
        return ;
    }

    r.insert({b[0],b[1]});
    for(int i=1;i<n-1;i++){
        l.insert({b[i],b[i-1]});
        r.insert({b[i],b[i+1]});
    }
    l.insert({b[n-1],b[n-2]});
    // for(auto [l,r] : r){
    //     cout<<l<<" "<<r<<"\n";
    // }
    ll ans=1;
    if(r.find({a[0],a[1]})==r.end()) ans++ ,fa[0]=true;
    for(int i=1;i<n-1;i++){
        if(l.find({a[i],a[i-1]})==l.end() && !fa[i-1]) ans++,fa[i-1]=true;
        if(r.find({a[i],a[i+1]})==r.end() && !fa[i]) ans++,fa[i]=true;
    }
    if(l.find({a[n-1],a[n-2]}) == l.end()&& !fa[n-2]) ans++;
    cout<<ans<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}