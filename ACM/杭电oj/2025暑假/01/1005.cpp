#include <bits/stdc++.h>
using ll = long long;
using namespace std;

struct UnionFind {
    vector<int> parent;
    vector<int> rank;

    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (rank[x] < rank[y]) {
            parent[x] = y;
        } else {
            parent[y] = x;
            if (rank[x] == rank[y]) {
                rank[x]++;
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        map<int, vector<pair<int, int>>> groups;

        for (int i = 0; i < m; i++) {
            int u, v, c;
            cin >> u >> v >> c;
            groups[c].push_back({u, v});
        }

        int cnt_super = n + 1;
        int max_node = n + m + 100000;
        vector<vector<pair<int, int>>> graph(max_node + 1);

        for (const auto& p : groups) {
            int c = p.first;
            const vector<pair<int, int>>& edges = p.second;

            set<int> node_set;
            for (const auto& e : edges) {
                node_set.insert(e.first);
                node_set.insert(e.second);
            }

            if (node_set.empty()) continue;
            vector<int> nodes(node_set.begin(), node_set.end());
            int num_nodes = nodes.size();
            unordered_map<int, int> node_to_id;
            for (int i = 0; i < num_nodes; i++) {
                node_to_id[nodes[i]] = i;
            }

            UnionFind uf(num_nodes);
            for (const auto& e : edges) {
                int u = e.first;
                int v = e.second;
                int id_u = node_to_id[u];
                int id_v = node_to_id[v];
                uf.unite(id_u, id_v);
            }

            unordered_map<int, vector<int>> components;
            for (int i = 0; i < num_nodes; i++) {
                int root = uf.find(i);
                components[root].push_back(nodes[i]);
            }

            for (const auto& comp : components) {
                int super_id = cnt_super++;
                for (int node : comp.second) {
                    graph[node].push_back({super_id, 1});
                    graph[super_id].push_back({node, 0});
                }
            }
        }

        vector<int> dist(max_node + 1, -1);
        deque<int> dq;

        dist[1] = 0;
        dq.push_back(1);

        while (!dq.empty()) {
            int u = dq.front();
            dq.pop_front();

            if (u == n) {
                break;
            }

            for (const auto& edge : graph[u]) {
                int v = edge.first;
                int w = edge.second;
                if (dist[v] == -1) {
                    dist[v] = dist[u] + w;
                    if (w == 0) {
                        dq.push_front(v);
                    } else {
                        dq.push_back(v);
                    }
                }
            }
        }

        cout << dist[n] << '\n';
    }

    return 0;
}