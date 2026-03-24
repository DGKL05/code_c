#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;ll k=0;ll m=0;
    cin>>n>>k>>m;
    vector<ll>arr(n);
    ll num=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ll ans=0;
    int j=0;
    for(int i=0;i<n;i++){
        // cout<<"qian : ";
        while(((j - i ) < k || num < m) && j < n){
            num+=arr[j];
            j++;
        }
        // cout<<"\nho : ";
        // cout<<i+1<<" "<<j+1<<" ";
        if(num >= m && ((j - i) >= k)){
            ans+=(n - j + 1);
        }
        // cout<<(n - j + 1)<<" "<<ans<<'\n';
        num-=arr[i];
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