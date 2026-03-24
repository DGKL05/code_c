#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> cost(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> cost[i][j];
        }
    }

    vector<int> dist(N, INT_MAX);
    vector<int> prev(N, -1);
    dist[0] = 0;

    for (int i = 0; i < N - 1; ++i) {
        for (int u = 0; u < N; ++u) {
            for (int v = 0; v < N; ++v) {
                if (cost[u][v] != 0 && dist[u] != INT_MAX) {
                    if (dist[u] + cost[u][v] < dist[v]) {
                        dist[v] = dist[u] + cost[u][v];
                        prev[v] = u;
                    }
                }
            }
        }
    }

    vector<int> path;
    int current = N - 1;
    while (current != -1) {
        path.push_back(current + 1); // 转换为1-based城市编号
        current = prev[current];
    }
    reverse(path.begin(), path.end());

    cout << dist[N - 1] << endl;
    for (size_t i = 0; i < path.size(); ++i) {
        if (i != 0) cout << " ";
        cout << path[i];
    }
    cout << endl;

    return 0;
}