#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;ll m=0;
    cin>>n>>m;
    vector<ll>v1(n),v2(n);
    ll max_n=0;ll min_n=0;
    for(int i=0;i<n;i++) cin>>v1[i];
    for(int i=0;i<n;i++) cin>>v2[i];
    for(int i=1;i<n;i++){
        v1[i]=max(v1[i],v1[i-1]);
    }
    for(int i=n-2;i>=0;i--){
        v2[i]=min(v2[i],v2[i+1]);
    }
    min_n=0;max_n=0;
    for(int i=0;i<n;i++){
        if(v2[i]<v1[i]){
            cout<<"NO\n";
            return ;
        }
        min_n+=v1[i];max_n+=v2[i];
    }
    if(min_n<=m && max_n>=m){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
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