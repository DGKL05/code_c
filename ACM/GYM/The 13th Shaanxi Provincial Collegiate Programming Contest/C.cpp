#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void test()
{
    ll a , b ;
    cin >> a >> b ;
    if(a == b || b == 1) cout << "-1\n" ;
    else {
        ll d = gcd(a , b) ;
        if(d == 1) {
            cout << b << "\n" ;
            return;
        }
        ll u = b ;
        while (u % d == 0) {
            u /= d ;
            d = gcd(a , u) ;
            if(d == 1) break;
        }
        if(gcd(a , u) == 1 && gcd(b , u) != 1) cout << u << "\n" ;
        else cout << "-1\n" ;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test();
    return 0;
}