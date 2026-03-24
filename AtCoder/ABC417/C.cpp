#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const int base = 200000;
const int N=6*1e7;
void test()
{
    int n;
    cin >> n;
    vector<int> v1(n);
    for (int i = 0; i < n; i++) {
        cin >> v1[i];
    }

    vector<int> cnt(N, 0);
    ll ans = 0;

    for (int j = 0; j < n; j++) {
        int r_val = (j + 1) - v1[j];
        int idx_r = r_val + base;
        ans += cnt[idx_r];

        int l_val = (j + 1) + v1[j];
        int idx_l = l_val + base;
        cnt[idx_l]++;
    }

    cout << ans << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}