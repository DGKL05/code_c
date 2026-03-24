#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int m=0;ll k=0;ll w=0;
    cin>>n>>m>>k>>w;
    vector<int>a,b;
    for(int i=0;i<n;i++){
        int idx=0;
        cin>>idx;
        // v1[idx]=1;
        a.push_back(idx);
    }
    for(int i=0;i<m;i++){
        int idx=0;
        cin>>idx;
        // v1[idx]=0;
        b.push_back(idx);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    // for(auto x:a){
    //     cout<<x<<" ";
    // }cout<<"\n";
    // for(auto x:b){
    //     cout<<x<<" ";
    // }cout<<"\n";
    set<ll>ans;
    int n1 = a.size();
    int n2 = b.size();
    int idx=0;
    for(int i=0;i<n2;i++){
        set<ll>temp;
        if()
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}