#include<bits/stdc++.h>
using namespace std;

#define RAN(i, f, t) for (int i=f; i<t; i++)

int t, n, m, p, q; 
set <int> se;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>t;
    while(t--) {
        se.clear();
        cin>>n>>m;
        int now = 0;
        RAN(i, 0, n) {
            cin>>p>>q;
            se.insert(now);
            now += p*48 / q;
        }
        now = 0;
        int ans = 0;
        RAN(i, 0, m) {
            cin>>p>>q;
            ans += se.count(now);
            now += p*48 / q;
        }
        cout<<ans<<"\n";
    }
    return 0;
}