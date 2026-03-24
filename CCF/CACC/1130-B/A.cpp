#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    vector<ll>arr(n);
    for(auto &x:arr) cin>>x;
    for(int i=0;i<n;i++) arr[i] = abs(arr[i]);
    sort(arr.begin(),arr.end());
    int j=0;
    ll ans=0;
    for(int i=0;i<n;i++){
        while(j<n && arr[j] <= 1LL*2*arr[i]){
            j++;
        }
        ans += (j-i-1);
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
