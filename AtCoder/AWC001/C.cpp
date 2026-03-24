#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int k=0;
    cin>>n>>k;
    vector<ll>arr(n);
    for(auto &x:arr) cin>>x;
    sort(arr.begin() , arr.end());
    ll ans=0;
    int idx = n-1;
    int num =0;
    while(num < k){
        num++;
        idx--;
    }
    for(int i=idx;i>=0;i--){
        ans+=arr[i];
    }
    cout<<ans<<"\n";
}
 
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}