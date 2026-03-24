#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const int N = 3*1e5+5;

priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> q1;
int n=0;int m=0;
ll arr[N];
bool fa[N];
vector<vector<pair<int,ll>>>v1;

int main()
{
    
    cin>>n>>m;
    v1.resize(n+1);
    for(int i=0;i<m;i++){
        int x=0;int y=0;ll w=0;
        cin>>x>>y>>w;
        v1[x].push_back({y,w});
    }
    for(int i=0;i<=n;i++) arr[i] = 1e18;
    q1.push({0,1});
    arr[1]=0;
    while(q1.size()){
        pair<ll,int>temp=q1.top();
        q1.pop();
        int x=temp.second;
        ll w=temp.first;
        if(fa[x]) continue;
        fa[x]=true;
        for(pair<int,ll> en : v1[x]){
            int u = en.first;ll w1=en.second;
            if(arr[u]>arr[x]+w1){
                arr[u]=arr[x]+w1;
                q1.push({arr[u],u});
            }
        }
    }

    for(int i=1;i<=n;i++) {
      if(arr[i] == 1e18) cout<<"-1 ";
      else cout<<arr[i]<<" ";
    }
    return 0;
}