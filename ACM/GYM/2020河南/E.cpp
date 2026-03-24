#include<bits/stdc++.h>
using namespace std;
using ll =long long;


void test()
{
    int n, k;
    cin >> n >> k;
    vector<int>v;
    vector<int>w(n+1);
    vector<int>l(n+1);
    vector<int>r(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin>>l[i]>>r[i]>>w[i];
        v.push_back(l[i]), v.push_back(r[i] + 1);
    }
    sort(v.begin(), v.end());
    int cnt = v.erase(unique(v.begin(), v.end()), v.end()) - v.begin();
    vector<int>num(cnt+1);
    vector<int>d(cnt+1);
    for (int i = 1; i <= n; i++)
    {
        int bg = lower_bound(v.begin(), v.end(), l[i]) - v.begin() + 1;
        int ed = lower_bound(v.begin(), v.end(), r[i] + 1) - v.begin() + 1;
        d[bg] ^= w[i], d[ed] ^= w[i];
        num[bg]++, num[ed]--;
    }
    int ans = -1;
    for (int i = 1; i <= cnt; i++)
    {
        d[i] ^= d[i - 1];
        num[i] += num[i - 1];
        if (num[i] >= k)
            ans = max(ans, d[i]);
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) test();
    return 0;
}