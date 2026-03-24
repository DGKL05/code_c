#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    vector<ll>arr(n);
    ll ans=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        ans=max(ans,arr[i]);
    }
    cout<<1LL*(n-2)*ans+arr[0]+arr[n-1]<<"\n";
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