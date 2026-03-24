#include <bits/stdc++.h>
using namespace std;

struct node {
    string name;
    int k;
    bool operator<(const node &a) const {
        if (name != a.name) return name < a.name;
        return k < a.k;
    }
    bool operator==(const node &a) const {
        return name == a.name && k == a.k;
    }
};
struct zheng {
    node tuo;
    node wei;
};

void test() {
    int n;
    cin >> n;
    vector<zheng> all_zheng;
    map<node, vector<int>> g; // 每个节点对应的出边编号
    set<string> all_core;
    for (int i = 0; i < n; i++) {
        string a, b;
        int d1, d2;
        cin >> a >> d1 >> b >> d2;
        node u = {a, d1};
        node v = {b, d2};
        all_zheng.push_back({u, v});
        g[u].push_back(i);
        all_core.insert(a);
        all_core.insert(b);
    }
    vector<int> ans_idx;
    int min_len = INT_MAX;
    for (const string& core : all_core) {
        node start = {core, 0};
        node end = {core, 1};
        queue<node> q;
        map<node, bool> vis;
        map<node, int> pre_zheng_idx; // 记录到达该节点的前驱推论编号
        vis[start] = true;
        pre_zheng_idx[start] = -1;
        q.push(start);
        vector<int> path_idx;
        bool found = false;
        while (!q.empty()) {
            node u = q.front(); q.pop();
            if (u.name == end.name && u.k == end.k) {
                // 回溯路径
                node cur = u;
                while (pre_zheng_idx[cur] != -1) {
                    int idx = pre_zheng_idx[cur];
                    path_idx.push_back(idx);
                    cur = all_zheng[idx].tuo;
                }
                reverse(path_idx.begin(), path_idx.end());
                found = true;
                break;
            }
            if (g.count(u)) {
                for (int idx : g[u]) {
                    node v = all_zheng[idx].wei;
                    if (!vis[v]) {
                        vis[v] = true;
                        pre_zheng_idx[v] = idx;
                        q.push(v);
                    }
                }
            }
        }
        if (found) {
            if ((int)path_idx.size() < min_len) {
                min_len = path_idx.size();
                ans_idx = path_idx;
            }
        }
    }
    vector<string> ans;
    for (int i = 0; i < (int)ans_idx.size(); i++) {
        zheng &z = all_zheng[ans_idx[i]];
        ans.push_back(z.tuo.name + " " + to_string(z.tuo.k));
        ans.push_back(z.wei.name + " " + to_string(z.wei.k));
    }
    for (int i = 0; i < (int)ans.size(); i++) {
        if (i > 0) cout << " ";
        cout << ans[i];
    }
    if (!ans_idx.empty()) {
        node start = all_zheng[ans_idx[0]].tuo;
        node end = all_zheng[ans_idx.back()].wei;
        cout << " = " << start.name << " " << start.k << " " << end.name << " " << end.k;
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin>>T;
    while (T--) test();
    return 0;
}