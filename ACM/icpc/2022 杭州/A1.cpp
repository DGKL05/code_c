#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    ll sum = 0;
    
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        sum = (sum + a[i]) % m;
    }
    
    ll g = gcd(n, m);
    ll C0 = 0;
    ll C1 = (n * (n + 1) / 2) % m;
    
    ll T0 = (sum + C0) % m;
    ll T1 = (sum + C1) % m;
    
    ll ans0 = T0 % g;
    ll ans1 = T1 % g;
    
    ll final_ans, final_d;
    if (ans0 <= ans1) {
        final_ans = ans0;
        final_d = 0;
    } else {
        final_ans = ans1;
        final_d = 1;
    }
    
    ll C = (final_d == 0) ? C0 : C1;
    ll T = (final_d == 0) ? T0 : T1;
    
    ll R = (final_ans - (sum + C)) % m;
    if (R < 0) R += m;
    
    ll final_s = -1;
    for (ll k = -n; k <= n; k++) {
        ll numerator = R - k * m;
        if (numerator % n == 0) {
            ll s = numerator / n;
            if (s >= 0 && s < m) {
                final_s = s;
                break;
            }
        }
    }
    
    if (final_s == -1) {
        final_s = 0;
    }
    
    cout << final_ans << endl;
    cout << final_s << " " << final_d << endl;
    
    return 0;
}