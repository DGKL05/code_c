#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct TopK {
    int K;
    multiset<int> small, big;

    ll sumBig = 0;

    TopK(int k = 0) : K(k) {}

    void balance() {

        while ((int)big.size() > K) {
            auto it = big.begin();

            int x = *it;

            sumBig -= x;

            big.erase(it);
            small.insert(x);
        }

        while ((int)big.size() < K && !small.empty()) {
            auto it = prev(small.end());

            int x = *it;

            small.erase(it);
            big.insert(x);

            sumBig += x;
        }

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

void test() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<ll> a(n + 1);
    vector<pair<ll, int>> ord;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        ord.push_back({a[i] , i});
    }

    sort(ord.begin(), ord.end());

    vector<ll> val;
    vector<vector<int>> pos;

    for (auto [x, p] : ord) {
        if (val.empty() || val.back() != x) {
            val.push_back(x);
            pos.push_back({});
        }

        pos.back().push_back(p);
    }

    set<int> zero;

    zero.insert(0);

    for (int i = 1; i <= n; i++) {
        zero.insert(i);
    }

    zero.insert(n + 1);

    TopK top(m + 1);

    auto activate = [&](int p) {

        auto it = zero.find(p);

        int L = *prev(it);
        int R = *next(it);
        int left = p - L - 1;
        int right = R - p - 1;
        int merged = R - L - 1;

        top.eraseOne(left);
        top.eraseOne(right);

        top.add(merged);

        zero.erase(it);
    };

    auto deactivate = [&](int p) {

        auto it = zero.lower_bound(p);

        int R = *it;
        int L = *prev(it);
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
    for (int r = 0; r < (int)val.size(); r++) {
        for (int p : pos[r]) {
            activate(p);
        }
        while ( l <= r &&top.query() >= k) {
            ans = min(ans , val[r] - val[l]);
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

    int T = 1;
    cin >> T;

    while (T--) test();

    return 0;
}