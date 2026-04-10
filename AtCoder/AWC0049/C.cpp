#include<bits/stdc++.h>
using namespace std;
using ll =long long;

int n;
struct DSU{
    vector<ll>dsu_po;
    vector<int>pre;
    vector<int>sz;
    vector<vector<ll>>idx;

    DSU (vector<ll>arr){
        dsu_po.resize(n+1);
        pre.resize(n+1);
        sz.resize(n+1);
        idx.resize(n+1);
        for(int i=0;i<=n;i++){
            pre[i] = i;
            dsu_po[i] = arr[i];
            sz[i] = 1;
        }
    }

    int find(int idx){
        return pre[idx] == idx ? idx : pre[idx] = find(pre[idx]);
    }

    void unit(int a,int b){
        a = find(a);
        b = find(b);
        if(a == b) return ;
        if(sz[a] < sz[b]) swap(a,b);
        pre[b] = a;
        sz[a] += sz[b];
        dsu_po[a] += dsu_po[b]; 
        if(dsu_po[b] != 0) idx[a].push_back(dsu_po[b]);
    }

};

void test()
{
    cin>>n;
    // vector<int>un(n+1);
    map<int,vector<int>>un;
    vector<ll>po(n+1);
    for(int i=2;i<=n;i++){
        int num=0;
        cin>>num;
        un[num].push_back(i);
    }

    for(int i=1;i<=n;i++){
        cin>>po[i];
    }
    DSU dsu(po);
    auto it = un.end();
    it--;
    while(it != un.begin()){
        // dsu.unit(it->first , it->second);
        for(auto x:it->second){
            dsu.unit(it->first , x);
        }
        it--;
    }

    for(auto x:it->second){
        dsu.unit(it->first , x);
    }

    it = un.end();
    it--;
    while(it != un.begin()){
        // dsu.unit(it->first , it->second);
        for(auto x:it->second){
            dsu.unit(it->first , x);
        }
        it--;
    }

    for(auto x:it->second){
        dsu.unit(it->first , x);
    }
    ll ans = 0;
    for(int i=1;i<=n;i++){
        cout<<dsu.dsu_po[i]<<" ";
    }cout<<"\n";

    for(int i=1;i<=n;i++){
        // cout<<dsu.dsu_po[i]<<"\n";
        sort(dsu.idx[i].begin() , dsu.idx[i].end());
        cout<<"========"<<i<<"=========\n";
        for(auto x:dsu.idx[i]) cout<<x<<" ";
        cout<<"\n";
        if(dsu.idx[i].size() < 2) continue;
        ans = max(ans , dsu.idx[i].back() - dsu.idx[i][0]);
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