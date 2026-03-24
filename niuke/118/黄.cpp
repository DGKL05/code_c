#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    vector<ll>a(n);
    for(auto &x:a){
        cin>>x;
    }
    // for(int i=n;i<v1.size();i++) v1[i]=1;
    int max_so_far = 0;
    int dp_prev = 1;
    int max_dp = 1;
    for (int i = 1; i < n; i++) {
        int dp_i = max_so_far + 1;
        if (gcd(a[i], a[i-1]) == 1) {
            if (dp_prev + 1 > dp_i) {
                dp_i = dp_prev + 1;
            }
        }
        if (dp_i > max_dp) {
            max_dp = dp_i;
        }
        if (dp_prev > max_so_far) {
            max_so_far = dp_prev;
        }
        dp_prev = dp_i;
    }
    int ans = n - max_dp;
    cout << ans << '\n';
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}