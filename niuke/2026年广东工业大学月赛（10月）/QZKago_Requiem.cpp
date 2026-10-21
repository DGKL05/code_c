
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void test()
{
    int n,m;
    cin>>n>>m;

    vector<vector<pair<int,int>>> g(n+1);

    for(int i=1;i<n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    const ll INF=1LL<<62;
    vector<ll> dis(n+1,INF);

    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        dis[x]=0;
    }

    vector<int> fa(n+1),order;
    vector<int> pw(n+1);
    order.reserve(n);
    order.push_back(1);

    for(int i=0;i<n;i++){
        int u=order[i];
        for(auto [v,w]:g[u]){
            if(v==fa[u]) continue;
            fa[v]=u;
            pw[v]=w;
            order.push_back(v);
        }
    }

    for(int i=n-1;i>0;i--){
        int u=order[i];
        int p=fa[u];
        dis[p]=min(dis[p],dis[u]+pw[u]);
    }

    for(int i=1;i<n;i++){
        int u=order[i];
        int p=fa[u];
        dis[u]=min(dis[u],dis[p]+pw[u]);
    }

    ll ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,dis[i]);
    }

    cout<<ans+1<<"\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T=1;
    while(T--) test();

    return 0;
}
