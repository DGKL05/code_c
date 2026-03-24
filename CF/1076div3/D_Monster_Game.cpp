#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    vector<ll>arr(n);
    vector<ll>v1(n);
    for(auto &x:arr) cin>>x;
    for(auto &x:v1) cin>>x;
    sort(arr.begin(),arr.end());
    for(int i=1;i<n;i++) v1[i] += v1[i-1];
    ll ans=0;
    for(int i = 1;i<=n;i++){
        int mid = 0;
        mid = arr[i-1];
        int num = lower_bound(arr.begin() , arr.end() , mid) - arr.begin();
        num = n - num;
        int l = 0;int r = n;
        int num1=0;
        while(l<r){
            int mid = (l+r)/2;
            if (v1[mid] <= num) {
                num1 = mid;              
                l = mid + 1;     
            } else {
                r = mid;        
            }
        }
        num1 = r;
        ans = max(1LL*mid*num1 , ans);
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
