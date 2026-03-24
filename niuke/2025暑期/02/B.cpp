#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> v1(61, 0);
    vector<int> v2(61, 0);
    for (ll x : a) {
        int h = -1;
        for (int i = 60; i >= 0; i--) {
            if (x & (1LL << i)) {
                if (h == -1) {
                    h = i;
                    v1[i]++;
                }
                v2[i]++;
            }
        }
    }
    bool fa = false;
    for (int i = 0; i <= 60; i++) {
        if (v1[i] >= 1 && v2[i] >= 2) {
            cout<<"NO\n";
            return ;
        }
    }
    cout<<"YES\n";  
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}