#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void test()
{
    int n=0;int m=0;
    cin>>n;
    vector<int>arr(n,0);
    unordered_map<int,list<int>>arridx;

    for(int i=0;i<n;i++) {
        cin>>arr[i];
        arridx[arr[i]].push_back(i);
    }
    cin>>m;
    while(m--){
        int op=0;
        cin>>op;
        if(op == 1){
            int x=0;int y=0;
            cin>>x>>y;
            auto it = arridx.find(x);
            if(it == arridx.end() || x == y) continue;
            arridx[y].splice(arridx[y].end() , arridx[x]);
        }else if(op == 2){
            int x=0;
            cin>>x;
            arridx[x].push_back(n+1);
            n++;
        }else {
            int x=0;
            cin>>x;
            arridx.erase(x);
        }
    }
    map<int,int>ans;
    auto it = arridx.begin();
    while(it != arridx.end()){
        for(auto x:it->second){
            ans[x]=it->first;
        }
        it++;
    }
    auto ik = ans.begin();
    while(ik != ans.end()){
        cout<<ik->second<<" ";
        ik++;
    }
    cout<<"\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin>>T;
    while(T--) test();
    return 0;
}