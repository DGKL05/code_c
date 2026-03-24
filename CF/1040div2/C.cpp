#include<bits/stdc++.h>
using namespace std;
using ll =long long;

vector<int> p;
vector<int> r;

int find(int x) {
    if (p[x] == 0) {
        p[x] = x;
        return x;
    }
    if (p[x] != x) {
        p[x] = find(p[x]);
    }
    return p[x];
}

bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (r[x] < r[y]) {
        swap(x, y);
    }
    p[y] = x;
    if (r[x] == r[y]) {
        r[x]++;
    }
    return true;
}

void test()
{
    int n;
    cin >> n;
    vector<pair<int, int>> e;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        e.push_back({a, b});
        v.push_back({a, b-1});
    }
    vector<pair<int, int>> s = v;
    sort(s.begin(), s.end());
    vector<pair<int, int>> m;
    long long u0 = 0;
    if (!s.empty()) {
        int l = s[0].first;
        int r = s[0].second;
        for (int j = 1; j < s.size(); j++) {
            if (s[j].first <= r + 1) {
                r = max(r, s[j].second);
            } else {
                m.push_back({l, r});
                l = s[j].first;
                r = s[j].second;
            }
        }
        m.push_back({l, r});
        for (const auto& x : m) {
            u0 += (x.second - x.first + 1);
        }
    }
    vector<bool> c(n, false);
    for (int i = 0; i < n; i++) {
        vector<pair<int, int>> t = s;
        int pos = -1;
        for (int j = 0; j < t.size(); j++) {
            if (t[j] == v[i]) {
                pos = j;
                break;
            }
        }
        if (pos != -1) {
            t.erase(t.begin() + pos);
        }
        vector<pair<int, int>> mt;
        long long ti = 0;
        if (t.empty()) {
            ti = 0;
        } else {
            sort(t.begin(), t.end());
            int l = t[0].first;
            int r = t[0].second;
            for (int j = 1; j < t.size(); j++) {
                if (t[j].first <= r + 1) {
                    r = max(r, t[j].second);
                } else {
                    mt.push_back({l, r});
                    l = t[j].first;
                    r = t[j].second;
                }
            }
            mt.push_back({l, r});
            for (const auto& x : mt) {
                ti += (x.second - x.first + 1);
            }
        }
        if (ti < u0) {
            c[i] = true;
        } else {
            c[i] = false;
        }
    }
    p.resize(2 * n + 1, 0);
    r.resize(2 * n + 1, 0);
    for(int i=0;i<2*n+1;i++) p[i]=i;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (c[i]) {
            int u = e[i].first;
            int v = e[i].second;
            if (find(u) != find(v)) {
                unite(u, v);
                ans.push_back(i);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (!c[i]) {
            int u = e[i].first;
            int v = e[i].second;
            if (find(u) != find(v)) {
                unite(u, v);
                ans.push_back(i);
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    if (!ans.empty()) {
        for (int i = 0; i < ans.size(); i++) {
            cout << (ans[i] + 1) << " ";
        }
        cout << '\n';
    } else {
        cout << '\n';
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