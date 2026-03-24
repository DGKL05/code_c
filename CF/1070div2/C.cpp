#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n = 0;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    vector<ll> ji, odd;
    for (ll x : arr) {
        if (x & 1) odd.push_back(x);
        else ji.push_back(x);
    }
    sort(ji.rbegin(), ji.rend());
    sort(odd.rbegin(), odd.rend());
    int osz = odd.size(), jisz = ji.size();
    vector<ll> sum(jisz + 1, 0);
    for (int i = 0; i < jisz; i++) {
        sum[i + 1] = sum[i] + ji[i];
    }
    vector<ll> ans(n + 1, 0);
    if (osz > 0) {
        for (int k = 1; k <= n; k++) {
            int num1 = max(0, k - osz);
            int num2 = min(jisz, k - 1);
            if (num2 < num1) {
                ans[k] = 0;
            } else {
                int p = (k - 1) % 2;
                int ji_idx = num2;
                if (ji_idx % 2 != p) {
                    ji_idx--;
                }
                if (ji_idx < num1) {
                    ans[k] = 0;
                } else {
                    int odd_idx = k - ji_idx;
                    if (odd_idx < 1 || odd_idx > osz) {
                        ans[k] = 0;
                    } else {
                        ans[k] = odd[0] + sum[ji_idx];
                    }
                }
            }
        }
    }
    for (int k = 1; k <= n; k++) {
        cout<<ans[k]<<" ";
    }
    cout<<"\n";
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