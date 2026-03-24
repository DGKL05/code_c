#include<bits/stdc++.h>
using namespace std;
using ll =long long;

struct node{
    ll idx;ll a;
};

void test()
{
    int n=0;int m=0;
    cin>>n>>m;
    vector<vector<int>>v1(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v1[i][j];
        }
    }
    vector<node>arr(m+1,{-1,-1});
    ll num=0;
    for(int i=0;i<m;i++){
        ll ans=1;
        for(int j=1;j<n;j++){
            if(v1[j][i]==v1[0][i]) ans++;
            else break;
        }
        // cout<<v1[0][i]<<" "<<ans<<"\n";
        if(ans>arr[v1[0][i]].a){
            arr[v1[0][i]].idx=i;
            arr[v1[0][i]].a=ans;
        }
    }
    for(int i=1;i<=m;i++){
        if(arr[i].idx != -1){
            num+=n-arr[i].a;
        }else num+=n;
    }
    cout<<num<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}