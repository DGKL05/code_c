#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct TopK {
    int K;

    // big 保存最大的 K 个
    multiset<int> small, big;

    ll sumBig = 0;

    TopK(int k = 0) : K(k) {}

    void balance() {
        // big 太多
        while ((int)big.size() > K) {
            auto it = big.begin();

            int x = *it;

            sumBig -= x;

            big.erase(it);
            small.insert(x);
        }

        // big 太少
        while ((int)big.size() < K && !small.empty()) {
            auto it = prev(small.end());

            int x = *it;

            small.erase(it);
            big.insert(x);

            sumBig += x;
        }

        // 保证 big 中全部 >= small 中全部
        while (!small.empty() && !big.empty()) {
            auto it1 = prev(small.end()); // small 最大
            auto it2 = big.begin();       // big 最小

            int x = *it1;
            int y = *it2;

            if (x <= y) break;

            small.erase(it1);
            big.erase(it2);

            small.insert(y);
            big.insert(x);

            sumBig += x - y;
        }
    }

    void add(int x) {
        if (x <= 0) return;

        if (!big.empty() && x >= *big.begin()) {
            big.insert(x);
            sumBig += x;
        } else {
            small.insert(x);
        }

        balance();
    }

    void eraseOne(int x) {
        if (x <= 0) return;

        auto it = big.find(x);

        if (it != big.end()) {
            sumBig -= x;
            big.erase(it);
        } else {
            it = small.find(x);
            small.erase(it);
        }

        balance();
    }

    ll query() {
        return sumBig;
    }
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<ll> a(n + 1);

    // value + position
    vector<pair<ll, int>> ord;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        ord.push_back({
            a[i],
            i
        });
    }

    sort(ord.begin(), ord.end());

    /*
        按值分组。

        val[i]     = 第 i 个不同的值
        pos[i]     = 值为 val[i] 的所有位置
    */

    vector<ll> val;
    vector<vector<int>> pos;

    for (auto [x, p] : ord) {
        if (val.empty() || val.back() != x) {
            val.push_back(x);
            pos.push_back({});
        }

        pos.back().push_back(p);
    }

    /*
        zero 表示当前不在 [val[l], val[r]]
        中的位置。

        即这些位置视为 0。
    */

    set<int> zero;

    zero.insert(0);

    for (int i = 1; i <= n; i++) {
        zero.insert(i);
    }

    zero.insert(n + 1);

    /*
        维护最大的 m+1 个连续 1 段
    */
    TopK top(m + 1);

    /*
        p 从 0 -> 1
    */
    auto activate = [&](int p) {

        auto it = zero.find(p);

        int L = *prev(it);
        int R = *next(it);

        /*
             L ... p ... R

        原来：

        (L,p)
        (p,R)

        两个 1 段

        现在合并成：

        (L,R)
        */

        int left = p - L - 1;
        int right = R - p - 1;

        int merged = R - L - 1;

        top.eraseOne(left);
        top.eraseOne(right);

        top.add(merged);

        zero.erase(it);
    };

    /*
        p 从 1 -> 0
    */
    auto deactivate = [&](int p) {

        auto it = zero.lower_bound(p);

        int R = *it;
        int L = *prev(it);

        /*
        原来：

        L [111 p 111] R

        一个整体。

        删除 p 后拆成两个。
        */

        int old = R - L - 1;

        int left = p - L - 1;
        int right = R - p - 1;

        top.eraseOne(old);

        top.add(left);
        top.add(right);

        zero.insert(p);
    };

    ll ans = (1LL << 62);

    int l = 0;

    /*
        双指针枚举值域：
        [val[l], val[r]]
    */

    for (int r = 0; r < (int)val.size(); r++) {

        // val[r] 加入窗口
        for (int p : pos[r]) {
            activate(p);
        }

        /*
            如果最大的 m+1 个连续段
            已经能够提供 >= k 个元素，

            当前值域合法。
        */
        while (
            l <= r &&
            top.query() >= k
        ) {

            ans = min(
                ans,
                val[r] - val[l]
            );

            /*
                缩小左端点
            */
            for (int p : pos[l]) {
                deactivate(p);
            }

            l++;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}