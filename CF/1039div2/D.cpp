#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin >> n;
    vector<ll> v1(n);
    
    for (auto &x : v1)
        cin >> x;
    ll sum = (1LL*n * (n + 1) * (n + 2))/6;
    for (ll i = 0; i + 1 < n; ++i) {
        if (v1[i] < v1[i + 1]) {
            sum -= 1LL * (i + 1) * (1LL*n - i - 1);
        }
    }
    cout << sum << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}