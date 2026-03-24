#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    map<ll,ll>m1;
    for(int i=0;i<n;i++){
        ll num=0;
        cin>>num;
        m1[num]++;
    }
    int l=0;int r=1e9;ll ans=0;
    while(l<=r){
        ll mid=(l+r)/2;
        ll num=0;
        for(auto [l,r] : m1){
            if(l>=mid) num+=r;
        }
        if(num>=mid){
            ans=max(mid,ans);
            l=mid+1;
        }else {
            r=mid-1;
        }
    }
    cout<<ans<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}