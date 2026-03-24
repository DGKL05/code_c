#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

const int MAXN = 105;
int parent[MAXN];

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unite(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx != fy) {
        parent[fy] = fx;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    // 初始化并查集
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }
    
    // 处理每条公交线路
    for (int i = 0; i < m; ++i) {
        int ci;
        cin >> ci;
        vector<int> stations(ci);
        for (int j = 0; j < ci; ++j) {
            cin >> stations[j];
        }
        if (ci < 2) continue; // 题目中ci≥2，但加上更安全
        // 合并线路中的所有车站到同一集合
        int first = stations[0];
        for (int j = 1; j < ci; ++j) {
            unite(first, stations[j]);
        }
    }
    
    // 统计各连通块的大小
    unordered_map<int, int> clusterSize;
    for (int i = 1; i <= n; ++i) {
        int root = find(i);
        clusterSize[root]++;
    }
    
    // 计算总不可达对数
    int totalPairs = n * (n - 1) / 2;
    int connectedPairs = 0;
    for (auto& p : clusterSize) {
        int size = p.second;
        connectedPairs += size * (size - 1) / 2;
    }
    int result = totalPairs - connectedPairs;
    
    cout << result <<"\n";
    
    return 0;
}