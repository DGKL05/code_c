#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<double>v1(n);
    v1[n-1]=arr[n-1]/100.0;
    for (int i = 0; i < n; i++) {
        v1[i] = arr[i] / 1000.0;
    }
    vector<double> dp(n);
    dp[n-1] = n; 
    for (int i = n-2; i >= 0; i--) {
        dp[i] = min(dp[i+1], (1 - v1[i]) * (i+1) + v1[i] * (20 + dp[i+1]));
    }
    cout << fixed << setprecision(10) << dp[0] << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}