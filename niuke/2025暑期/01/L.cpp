#include<bits/stdc++.h>
using namespace std;
using ll =long long;

struct Fenw {
    int n;
    vector<int> tree;

    Fenw(int size) {
        n = size;
        tree.assign(n + 1, 0);
    }

    void update(int index, int delta) {
        int i = index + 1;
        while (i <= n) {
            tree[i] += delta;
            i += (i & -i);
        }
    }

    int sum(int index) {
        if (index < 0) return 0;
        int i = index + 1;
        int s = 0;
        while (i > 0) {
            s += tree[i];
            i -= (i & -i);
        }
        return s;
    }
};

int get(vector<ll>& arr, ll val) {
    return lower_bound(arr.begin(), arr.end(), val) - arr.begin();
}

void test()
{
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<pair<int, ll>> Q;
    vector<ll> arr = a;
    vector<ll> v1 = a;
    for (int i = 0; i < q; i++) {
        int p, v;
        cin >> p >> v;
        p--;
        Q.push_back({p, v});
        int num = v1[p] + v;
        arr.push_back(num);
        v1[p] = num;
    }
    sort(arr.begin(), arr.end());
    auto last = unique(arr.begin(), arr.end());
    arr.erase(last, arr.end());

    int m = arr.size();
    Fenw fenw(m);
    v1 = a;
    for (int i = 0; i < n; i++) {
        int pos = get(arr, a[i]);
        fenw.update(pos, 1);
    }
    int d0 = n / 2;
    int top = n - d0;
    for (int i = 0; i < q; i++) {
        int p = Q[i].first;
        ll v = Q[i].second;
        ll old = v1[p];
        ll num = old + v;
        ll pos_old = get(arr, old);
        ll pos_new = get(arr, num);
        fenw.update(pos_old, -1);
        fenw.update(pos_new, 1);
        v1[p] = num;
        int l = 0, r = m - 1;
        int idx = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int s = fenw.sum(mid);
            if (s <= top) {
                idx = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (idx == -1) {
            cout << 0 << '\n';
        } else {
            int cnt = fenw.sum(idx);
            cout << cnt << '\n';
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}