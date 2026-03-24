#include<bits/stdc++.h>
using namespace std;
using ll =long long;

vector<vector<int>>arr;

struct node{
    int idx;
    vector<int>a;
};

vector<bool>dis;
int ans = 0;
vector<int>ansarr;

void bfs(int st){
    queue<node>q1;
    q1.push({st,{st}});
    dis[st] = true;
    ansarr.push_back(st);
    while(q1.size()){
        auto x1 = q1.front();
        q1.pop();
        for(auto x:arr[x1.idx]){
            if(dis[x]) continue ;
            dis[x] = true;
            vector<int>temp = x1.a;
            temp.push_back(x);
            q1.push({x,temp});
            if(ansarr.size() < temp.size()){
                ansarr = temp;
            }
        }
    }
}

void test()
{
    int n=0;
    cin>>n;
    arr.resize(n);
    dis.resize(n);
    vector<bool>fa(n,false);
    for(int i=0;i<n;i++){
        int k = 0;
        cin>>k;
        for(int j=0;j<k;j++){
            int p=0;
            cin>>p;
            arr[i].push_back(p);
            fa[p] = true;
        }
        sort(arr[i].begin() , arr[i].end());
    }
    int st = 0;
    while(true){
        if(fa[st]) st++;
        else break;
    }
    bfs(st);
    cout<< ansarr.size() << "\n";
    int n1 = ansarr.size();
    for(int i=0;i<n1;i++){
        cout<<ansarr[i];
        if(i != n1 - 1) cout<<" ";
    }
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