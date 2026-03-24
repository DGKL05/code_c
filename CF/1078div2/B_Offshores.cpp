#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;ll x=0; ll y=0;
    cin>>n>>x>>y;
    vector<ll>arr(n);
    for(auto &x:arr) cin>>x;
    sort(arr.begin() , arr.end());
    for(int i=0;i<n-1;i++){
        arr[i] = arr[i] * (y/x);
    }
    ll ans = 0;
    for(auto x:arr) {
        ans+=x;
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