#include<bits/stdc++.h>
using namespace std;
using ll =long long;

vector<int>ans;
vector<int>arr;
vector<vector<int>>g;
vector<bool>fa;

struct node {
    int idx;
    int val;
};

void bfs(int idx){
    queue<node>q1;
    q1.push({idx,0});
    fa[idx] = true;
    ans[arr[idx]] = max(ans[arr[idx]] , 0);
    while(q1.size()){
        auto x = q1.front();q1.pop();
        for(auto tx : g[x.idx]){
            if(fa[tx]) continue;
            ans[arr[tx]] = max(ans[arr[tx]] , x.val+1);
            fa[tx] = true;
            q1.push({tx , x.val+1});
        }
    }
}

void test()
{
    int n=0;int m=0;int k=0;
    cin>>n>>m>>k;
    ans.resize(k+1,0);
    arr.resize(n+1,0);
    fa.resize(n+1,false);
    g.resize(n+1);
    for(int i=0;i<n;i++){
        cin>>arr[i+1];
    } 
    for(int i=0;i<m;i++){
        int x=0;int y=0;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    bfs(1);

    for(int i=0;i<k;i++){
        cout<<ans[i+1]<<" ";
    }
    cout<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}