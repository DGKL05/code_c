#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
set<pair<int, int>> edges;
int ans = 100000000;

vector<vector<int>> get_combinations(vector<int>& arr, int k) {
    if (k == 0) return {{}};
    vector<vector<int>> res;
    int len = arr.size();
    if (k > len) return res;
    vector<bool> used(len, false);
    for (int i = 0; i < k; i++) 
        used[i] = true;
    do {
        vector<int> temp;
        for (int i = 0; i < len; i++) 
            if (used[i]) 
                temp.push_back(arr[i]);
        res.push_back(temp);
    } while (prev_permutation(used.begin(), used.end()));
    return res;
}

void dfs(int mask, vector<pair<int, int>> now_edges) {
    if (mask == 0) {
        set<pair<int, int>> H(now_edges.begin(), now_edges.end());
        int same = 0;
        for (auto e : edges) {
            if (H.find(e) != H.end()) 
                same++;
        }
        int cost = m + n - 2 * same;
        if (cost < ans) 
            ans = cost;
        return;
    }
    int start = -1;
    for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) {
            start = i;
            break;
        }
    }
    vector<int> others;
    for (int i = 0; i < n; i++) {
        if (i == start) continue;
        if (mask & (1 << i)) 
            others.push_back(i);
    }
    int cnt = others.size();
    for (int t = 2; t <= cnt; t++) {
        vector<vector<int>> all_comb = get_combinations(others, t);
        for (auto comb : all_comb) {
            vector<int> path = comb;
            sort(path.begin(), path.end());
            do {
                if (path[0] < path[t-1]) {
                    vector<pair<int,int>> cycle;
                    int u = start, v = path[0];
                    cycle.push_back({min(u,v), max(u,v)});
                    for (int i = 0; i < t-1; i++) {
                        u = path[i]; v = path[i+1];
                        cycle.push_back({min(u,v), max(u,v)});
                    }
                    u = path[t-1]; v = start;
                    cycle.push_back({min(u,v), max(u,v)});
                    int new_mask = mask;
                    new_mask ^= (1 << start);
                    for (int x : comb) 
                        new_mask ^= (1 << x);
                    int left = __builtin_popcount(new_mask);
                    if (left == 1 || left == 2) 
                        continue;
                    vector<pair<int,int>> new_edges = now_edges;
                    new_edges.insert(new_edges.end(), cycle.begin(), cycle.end());
                    dfs(new_mask, new_edges);
                }
            } while (next_permutation(path.begin(), path.end()));
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
        edges.insert({a, b});
    }
    dfs((1 << n) - 1, {});
    cout << ans << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int T = 1;
    // cin >> T;
    while(T--) test(); 
    return 0;
}