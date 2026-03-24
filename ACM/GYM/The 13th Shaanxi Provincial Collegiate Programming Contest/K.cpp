#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5+5;

void test()
{
    ll n, m, x, y;
    cin >> n >> m >> x >> y;
    if(n==0&&m==0){
        cout << 0 << endl;
        return;
    }
    if(n==0){
        if(x>y){
            cout << x << endl;
            return;
        }
        else{
            cout << m * y << endl;
            return;
        }
    }
    if(m==0){
        ll ans = 0;
        ans = max(x + (n - 1) * y, n * y);
        cout << ans << endl;
        return;
    }
    ll ans = 0, res = 0;
    if(y==0){
        cout << x << endl;
        return;
    }
    if(x>y)
        ans = x + n * y;
    else
        ans = n * y + m * y;
    x--;
    ll tt = x / y;
    x++;
    //cout << x << endl;
    if(tt>0&&tt<=n)
        res = max(ans, x + (n + m - tt) * y);
    else
        res = ans;
    cout << res << endl;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test();
    return 0;
}