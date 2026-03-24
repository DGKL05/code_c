#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
set<pair<int, int>> graph_edges;
int min_ops = 100000000;

vector<vector<int>> get_combinations(vector<int>& arr, int k) {
    if (k == 0) return {{}};
    vector<vector<int>> res;
    int n_arr = arr.size();
    if (k > n_arr) return res;
    vector<bool> mask(n_arr, false);
    for (int i = 0; i < k; i++) 
        mask[i] = true;
    do {
        vector<int> comb;
        for (int i = 0; i < n_arr; i++) 
            if (mask[i]) 
                comb.push_back(arr[i]);
        res.push_back(comb);
    } while (prev_permutation(mask.begin(), mask.end()));
    return res;
}

void rec(int mask, vector<pair<int, int>> edges_so_far) {
    if (mask == 0) {
        set<pair<int, int>> H(edges_so_far.begin(), edges_so_far.end());
        int common = 0;
        for (auto e : graph_edges) {
            if (H.find(e) != H.end()) 
                common++;
        }
        int cost = m + n - 2 * common;
        if (cost < min_ops) 
            min_ops = cost;
        return;
    }
    // find the smallest vertex in mask
    int v0 = -1;
    for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) {
            v0 = i;
            break;
        }
    }
    vector<int> rem;
    for (int i = 0; i < n; i++) {
        if (i == v0) continue;
        if (mask & (1 << i)) 
            rem.push_back(i);
    }
    int cnt_rem = rem.size();
    // t: number of additional vertices in the cycle (so the cycle size = t+1)
    for (int t = 2; t <= cnt_rem; t++) {
        vector<vector<int>> comb_list = get_combinations(rem, t);
        for (auto comb : comb_list) {
            vector<int> tmp = comb;
            sort(tmp.begin(), tmp.end());
            do {
                if (tmp[0] < tmp[t-1]) {
                    vector<pair<int,int>> cycle_edges;
                    // edge from v0 to tmp[0]
                    int u = v0, v = tmp[0];
                    cycle_edges.push_back({min(u,v), max(u,v)});
                    // edges in the path: tmp[0] to tmp[1], ... , tmp[t-2] to tmp[t-1]
                    for (int i = 0; i < t-1; i++) {
                        u = tmp[i]; v = tmp[i+1];
                        cycle_edges.push_back({min(u,v), max(u,v)});
                    }
                    // last edge: from tmp[t-1] to v0
                    u = tmp[t-1]; v = v0;
                    cycle_edges.push_back({min(u,v), max(u,v)});
                    int new_mask = mask;
                    new_mask ^= (1 << v0);
                    for (int x : comb) 
                        new_mask ^= (1 << x);
                    int cnt_remaining = __builtin_popcount(new_mask);
                    // Prune: skip if the remaining set has 1 or 2 vertices (cannot form a cycle)
                    if (cnt_remaining == 1 || cnt_remaining == 2) 
                        continue;
                    vector<pair<int,int>> new_edges = edges_so_far;
                    new_edges.insert(new_edges.end(), cycle_edges.begin(), cycle_edges.end());
                    rec(new_mask, new_edges);
                }
            } while (next_permutation(tmp.begin(), tmp.end()));
        }
    }
}

void test() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        if (a > b) swap(a, b);
        graph_edges.insert({a, b});
    }
    rec((1 << n) - 1, {});
    cout << min_ops << endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int T = 1;
    // cin >> T;
    while(T--) test(); 
    return 0;
}