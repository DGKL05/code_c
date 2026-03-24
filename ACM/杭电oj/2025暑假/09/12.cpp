#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int m=0;
    cin>>n>>m;
    map<int,set<int>>m1;
    vector<int>arr(n+1);
    vector<int>v1;
    for(int i=0;i<m;i++){
        int idx=0;
        cin>>idx;
        if(arr[idx]==0){
            v1.push_back(idx);
        }
        arr[idx]++;
    }
    int n1=v1.size();
    for(int i=0;i<n1;i++){
        m1[arr[v1[i]]].insert(v1[i]);
    }
    vector<int>v2;
    auto it=m1.end();
    it--;
    while(it!=m1.begin()){
        for(auto x:it->second){
            v2.push_back(x);
        }
        it--;
    }
    it=m1.begin();
    for(auto x:it->second){
        v2.push_back(x);
    }
    ll ans=0;
    
    for(int i=0;i<n1;i++){
        // cout<<v2[i]<<"\n";
        if(v2[i]!=v1[i]){
            ans++;
        }
    }
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