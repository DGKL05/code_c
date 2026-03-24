#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void test()
{
    int n, k;
    ll c;
    cin>>n>>k>>c;
    vector<ll>v1(n);
    for (int i = 0; i < n; i++) {
        cin>>v1[i];
    }
    if ( k == 0) {
        cout<<"0\n";
        return;
    }
    vector<ll>w(n);
    for (int i = 0; i < n; i++) {
        w[i]=v1[i]-c*(ll)i;
    }
    sort(w.begin(), w.end(), greater<ll>());
    ll ans=0;
    for (int i = 0; i < k; i++) {
        ans+=w[i];
    }
    ll num=1LL*(ll)c*(ll)k*(k-1)/2;
    ans+=num;
    cout<<ans<<"\n";
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    int T = 1;
    // cin >> T;
    while (T--) test();
    return 0;
}