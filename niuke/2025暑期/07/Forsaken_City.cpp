#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    vector<int>v1(n),v2(n);
    for(int i=0;i<n;i++){
        cin>>v1[i];
        // cout<<v1[i]<<" ";
    }
    v2[n-1]=v1[n-1];
    for(int i=n-2;i>=0;i--){
        v2[i]=min(v2[i+1],v1[i]);
        // cout<<v2[i]<<" ";
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(v1[i]-v2[i],ans);
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