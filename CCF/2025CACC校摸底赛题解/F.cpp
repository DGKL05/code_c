#include<bits/stdc++.h>
using namespace std;
using ll =long long;

vector<vector<int>>arr;

struct node{
    int idx;
    int pre;
};

int ans;

void bfs(int st){

    queue<node>q1;
    q1.push({st,st});

    while(q1.size()){
        auto t = q1.front();
        q1.pop();
        ans = t.idx;
        for(auto next : arr[t.idx]){
            if(next == t.pre) continue;
            q1.push({next,t.idx});
        }
    }
}
void test()
{
    int n=0;
    cin>>n;
    arr.resize(n);
    vector<bool>fa(n);
    for(int i=0;i<n;i++){
        int m=0;
        cin>>m;
        for(int j=0;j<m;j++){
            int a=0;
            cin>>a;
            a--;
            fa[a] = true;
            arr[i].push_back(a);
        }
    }
    int st=-1;
    while(fa[++st]);
    bfs(st);

    cout<<ans+1<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}