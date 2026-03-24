#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int w=0;
    cin>>n>>w;
    vector<ll>arr(n);
    vector<ll>mod((2*w),0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        mod[(i+1)%(2*w)]+=arr[i];
    }

    ll ans = 0;
    for(int i=0;i<w;i++) {
        ans+=mod[i];
    }
    // for(int i=0;i<2*w;i++) cout<<mod[i]<<"\n";
    ll temp=ans;
    for(int i=1;i<2*w;i++){
        // temp=ans;
        // cout<<"temp = "<<temp<<"\n";
        temp-=mod[i-1];
        // cout<<"temp = "<<temp<<"\n";
        temp+=mod[(i+w-1)%(2*w)];
        // cout<<"temp = "<<temp<<"\n";
        // cout<<i<<" "<<(i+w-1)%(2*w)<<" "<<temp<<"\n";
        ans=min(ans,temp);
    }
    cout<<ans<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}