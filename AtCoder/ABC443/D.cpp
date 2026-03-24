#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    vector<ll> arr(n); // 用long long避免求和溢出
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    vector<ll> temp = arr; 
    for (int i = 1; i < n; ++i) {
        temp[i] = min(temp[i], temp[i-1] + 1);
    }
    for (int i = n-2; i >= 0; --i) {
        temp[i] = min(temp[i], temp[i+1] + 1);
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += abs(arr[i] - temp[i]);
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