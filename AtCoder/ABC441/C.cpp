#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int k=0;ll x=0;
    cin>>n>>k>>x;
    ll ans=0;
    vector<ll>arr(n);
    for(auto &x:arr){
        cin>>x;
    }
    sort(arr.begin(),arr.end());
    vector<ll>sum(n+1);
    for(int i=1;i<=n;i++){
        sum[i] = sum[i-1] + arr[i-1];
    }
    if(sum[k] < x){
        cout<<"-1\n";
        return ;
    }
    int l = 1, r = n;
    while (l <= r) {
        int mid = l + (r - l) / 2; 
        ll s = max(0LL, (ll)k + mid - n);

        long long temp = 0;
        if (s > 0) {
            int l = n - mid;
            int r = l + s - 1; 
            temp = sum[r + 1] - sum[l];
        }
        if (temp >= x) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
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