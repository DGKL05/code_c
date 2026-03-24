#include<bits/stdc++.h>
using namespace std;
using ll =long long;
ll p3[25];
void test()
{
    ll n;
    cin >> n;
    vector<int> digits;
    ll temp = n;
    while (temp) {
        digits.push_back(temp % 3);
        temp /= 3;
    }
    ll ans = 0;
    for (int k = 0; k < digits.size();  k++) {
        if (digits[k]) {
            ll c = p3[k+1];
            if (k >= 1) {
                c += 1LL*k * p3[k-1];
            }
            ans += 1LL*digits[k] * c;
        }
    }
    cout << ans << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    p3[0] = 1;
    for (int i = 1; i < 25; i++) {
        p3[i] = p3[i-1] * 3;
    }
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}