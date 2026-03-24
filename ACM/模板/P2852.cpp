#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int N = 2*1e5+10;

int s[N];
int n;
int m, p, rk[N * 2], oldrk[N], sa[N * 2], id[N], cnt[N],height[N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int k1=0;
    cin>>n>>k1;
    // cin>>s;
    s[0]=-1;
    for(int i=0;i<n;i++){
        int s1;
        cin>>s1;
        s[i+1]=s1;
    }
    k1--;
    m = 258;
    // cout<<s<<"\n";
    for (int i = 1; i <= n; i++) cnt[rk[i] = s[i]]++;
    for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
    for (int i = n; i >= 1; i--) sa[cnt[rk[i]]--] = i;

    for (int w = 1;; w <<= 1, m = p) {  // m = p 即为值域优化
        int cur = 0;
        for (int i = n - w + 1; i <= n; i++) id[++cur] = i;
        for (int i = 1; i <= n; i++)
        if (sa[i] > w) id[++cur] = sa[i] - w;

        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++) cnt[rk[i]]++;
        for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
        for (int i = n; i >= 1; i--) sa[cnt[rk[id[i]]]--] = id[i];

        p = 0;
        memcpy(oldrk, rk, sizeof(oldrk));
        for (int i = 1; i <= n; i++) {
        if (oldrk[sa[i]] == oldrk[sa[i - 1]] &&
            oldrk[sa[i] + w] == oldrk[sa[i - 1] + w])
            rk[sa[i]] = p;
        else
            rk[sa[i]] = ++p;
        }

        if (p == n) break;  // p = n 时无需再排序
    }
    for (int i = 1, k = 0; i <= n; ++i) {
        if (rk[i] == 0) continue;
        if (k) --k;
        while (s[i + k] == s[sa[rk[i] - 1] + k]) ++k;
        height[rk[i]] = k;
    }

    multiset<int>s1;
    int ans=0;
    for(int i=1;i<=n;i++){
        s1.insert(height[i]);
        // cout<<height[i]<<" ";
        if(i>k1) s1.erase(s1.find(height[i-k1]));
        ans=max(ans,*s1.begin());
    }
    cout<<ans<<"\n";
    return 0;
}