#include<bits/stdc++.h>
using namespace std;
using ll =long long;

struct node{
    string name;
    int k;
    bool operator<(const node &a) const {
        if(name != a.name) return name < a.name;
        return k < a.k;
    }
};
struct zheng{
    node tuo;
    node wei;
    int idx; // 唯一编号
    bool operator<(const zheng& z) const {
        if (tuo.name != z.tuo.name) return tuo.name < z.tuo.name;
        if (tuo.k != z.tuo.k) return tuo.k < z.tuo.k;
        if (wei.name != z.wei.name) return wei.name < z.wei.name;
        if (wei.k != z.wei.k) return wei.k < z.wei.k;
        return idx < z.idx;
    }
};
struct State {
    vector<node> path;
    set<int> used_zheng_idx; 
};
void test()
{
    int n;
    cin >> n;
    map<node, vector<zheng>> g; 
    vector<zheng> all_zheng;
    set<node> all_points;
    for (int i = 0; i < n; i++) {
        string a, b;
        int d1, d2;
        cin >> a >> d1 >> b >> d2;
        node u = {a, d1};
        node v = {b, d2};
        zheng z = {u, v, i};
        g[u].push_back(z);
        all_zheng.push_back(z);
        all_points.insert(u);
        all_points.insert(v);
    }
    vector<zheng> ans_chain;
    int min_len = INT_MAX;
    for (const auto& p : all_points) {
        node start = p;
        node end = {p.name, 1 - p.k};
        queue<pair<vector<zheng>, set<int>>> q;
        for (auto& z : g[start]) {
            q.push({{z}, {z.idx}});
        }
        set<pair<node, set<int>>> vis;
        while (!q.empty()) {
            auto [chain, used] = q.front(); q.pop();
            zheng last = chain.back();
            if (last.wei.name == end.name && last.wei.k == end.k) {
                if ((int)chain.size() < min_len) {
                    ans_chain = chain;
                    min_len = chain.size();
                }
                break;
            }
            for (auto& z : g[last.wei]) {
                if (used.count(z.idx)) continue;
                auto new_chain = chain;
                new_chain.push_back(z);
                auto new_used = used;
                new_used.insert(z.idx);
                if (vis.count({z.wei, new_used})) continue;
                vis.insert({z.wei, new_used});
                q.push({new_chain, new_used});
            }
        }
        if (!ans_chain.empty()) break;
    }
    if (!ans_chain.empty()) {
        // 输出推论链
        cout << ans_chain[0].tuo.name << " " << ans_chain[0].tuo.k << " ";
        for (auto& z : ans_chain) {
            cout << z.wei.name << " " << z.wei.k << " ";
        }
        cout << "= " << ans_chain[0].tuo.name << " " << ans_chain[0].tuo.k << " ";
        cout << ans_chain.back().wei.name << " " << ans_chain.back().wei.k << endl;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}