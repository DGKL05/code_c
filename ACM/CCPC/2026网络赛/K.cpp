#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 998244353;
const ll INF = 4e18;

struct node{
    int v;
    ll w;
};

ll qpow(ll a,ll b){
    ll ans = 1;
    while(b){
        if(b&1) ans = ans*a%MOD;
        a = a*a%MOD;
        b>>=1;
    }
    return ans;
}

void test(){
    int n,m,t;
    cin>>n>>m>>t;

    string s;
    cin>>s;

    vector<vector<node>>g(n+1);
    vector<int>in(n+1,0);
    vector<int>deg(n+1,0);

    for(int i=0;i<m;i++){
        int u,v;
        ll w;
        cin>>u>>v>>w;

        g[u].push_back({v,w});
        in[v]++;
        deg[u]++;
    }

    queue<int>q;
    vector<int>top;

    for(int i=1;i<=n;i++){
        if(in[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();

        top.push_back(u);

        for(auto [v,w]:g[u]){
            in[v]--;
            if(in[v] == 0){
                q.push(v);
            }
        }
    }

    vector<ll>dis(n+1,INF);
    vector<ll>cnt(n+1,0);
    vector<ll>dp(n+1,0);

    dis[t] = 0;
    cnt[t] = 1;
    dp[t] = 0;

    for(int i=n-1;i>=0;i--){
        int u = top[i];

        if(u == t) continue;

        for(auto [v,w]:g[u]){
            dis[u] = min(dis[u],dis[v]+w);
        }

        ll sum = 0;

        for(auto [v,w]:g[u]){

            if(dis[u] == dis[v]+w){
                cnt[u] += cnt[v];
                cnt[u] %= MOD;
            }

            if(s[u-1] == '1'){
                if(dis[u] == dis[v]+w){
                    ll now = (w%MOD + dp[v])%MOD;

                    sum += cnt[v]*now%MOD;
                    sum %= MOD;
                }
            }else{
                ll now = (w%MOD + dp[v])%MOD;

                sum += now;
                sum %= MOD;
            }
        }

        if(s[u-1] == '1'){
            dp[u] = sum*qpow(cnt[u],MOD-2)%MOD;
        }else{
            dp[u] = sum*qpow(deg[u],MOD-2)%MOD;
        }
    }

    for(int i=1;i<=n;i++){
        cout<<dp[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T = 1;
    // cin>>T;

    while(T--) test();

    return 0;
}