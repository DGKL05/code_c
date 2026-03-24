#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    vector<int>v1(n);
    for(int i=0;i<n;++i){
        cin>>v1[i];
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        ll l=0;ll r=0;
        for(int j=0;j<i;j++) if(v1[j]>v1[i]) l++;
        for(int j=i+1;j<n;j++) if(v1[j]>v1[i]) r++;
        ans+=(min(l,r));
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