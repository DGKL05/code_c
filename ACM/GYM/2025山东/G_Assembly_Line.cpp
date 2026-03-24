#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;ll k;
    cin>>n>>k;
    vector<pair<ll,ll>>v1(n);
    vector<ll>sum(n);
    for(int i=0;i<n;i++){
        ll t,w;
        cin>>w>>t;
        v1[i]={t,w};
    }
    // sort(v1.begin(),v1.end());
    ll ans=-1;
    for(int i=0;i<n;i++){
        ll t=v1[i].first;
        ll w=v1[i].second;
        ans=max(t+(k-w),ans);
        // cout<<"time = "<<t+(k-w)<<"\n";
        sum[i]=t+(k-w);
        //21 5 6 7 8 9 10
        //2 1 2 3
    }
    sort(sum.begin(),sum.end());
    for(int i=1;i<n;i++){
        sum[i]=max(sum[i-1]+1,sum[i]);
    }
    // if(temp!=ans) ans--;
    cout<<sum[n-1]<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}