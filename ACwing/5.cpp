#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> matrix(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> matrix[i][j];
        }
    }

    // 构建邻接表和入度数组
    vector<vector<pair<int, int>>> adj(N + 1); // 节点1~N的邻接表
    vector<int> indegree(N + 1, 0);
    for (int u = 1; u <= N; ++u) {
        for (int v = 1; v <= N; ++v) {
            int cost = matrix[u - 1][v - 1];
            if (cost != 0) {
                adj[u].emplace_back(v, cost);
                indegree[v]++;
            }
        }
    }

    // Kahn算法拓扑排序
    queue<int> q;
    for (int i = 1; i <= N; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo_order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo_order.push_back(u);
        for (auto& edge : adj[u]) {
            int v = edge.first;
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    // 初始化距离和前驱数组
    vector<long long> dist(N + 1, LLONG_MAX);
    vector<int> pre(N + 1, -1);
    dist[1] = 0;

    // 按照拓扑顺序处理每个节点
    for (int u : topo_order) {
        if (dist[u] == LLONG_MAX) continue;
        for (auto& edge : adj[u]) {
            int v = edge.first;
            int cost = edge.second;
            if (dist[u] + cost < dist[v]) {
                dist[v] = dist[u] + cost;
                pre[v] = u;
            }
        }
    }

    // 回溯路径
    vector<int> path;
    int current = N;
    while (current != -1) {
        path.push_back(current);
        current = pre[current];
    }
    reverse(path.begin(), path.end());

    // 输出结果
    cout << dist[N] << endl;
    for (size_t i = 0; i < path.size(); ++i) {
        if (i > 0) cout << " ";
        cout << path[i];
    }
    cout << endl;

    return 0;
}