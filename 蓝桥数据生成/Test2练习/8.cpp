#include <bist/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;
vector<int> pre(MAXN);

// 查找元素 x 的根节点，并进行路径压缩
int root(int x) {
    return pre[x] = (pre[x] == x ? x : root(pre[x]));
}

// 合并元素 x 和 y 所在的集合
void unite(int x, int y) {
    int rootX = root(x);
    int rootY = root(y);
    if (rootX != rootY) {
        pre[rootX] = rootY;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    // 初始化并查集
    for (int i = 1; i <= 2 * n; ++i) {
        pre[i] = i;
    }

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;

        // 判断是否矛盾
        if (root(x) == root(y) || root(x + n) == root(y + n)) {
            // 如果 x 和 y 在同一个集合，或者 x + n 和 y + n 在同一个集合，说明出现矛盾
            cout << x << endl;
            return 0;
        }

        // 合并关系
        unite(x, y + n);
        unite(x + n, y);
    }

    return 0;
}