#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    ll n = 0;
    cin>>n;
    ll ans = 1;
    for (int i = 1; i * i <= n; i++){
        if (n % i == 0){
            ans = max(ans, 1LL*i);
            if (i > 2) ans = max(ans, 1LL*n / i);
        }
    }
    cout << ans << '\n';
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