#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;

int n, m;
struct Node {
    int l, r, p = 0, idx;
    ll mav, miv; // mav: 最大值, miv: 最小值
} tree[N << 2]; // 操作树，大小为4*N

ll a[N]; // 存储轮次结果（第1轮到第n-1轮的值）
ll bit[N]; // 树状数组

// 树状数组：低位函数
int lowbit(int x) {
    return x & -x;
}

// 树状数组：更新操作
void update(int x, ll v) {
    for (int i = x; i <= n - 1; i += lowbit(i)) {
        bit[i] += v;
    }
}

// 树状数组：查询前缀和
ll query(int x) {
    ll res = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
        res += bit[i];
    }
    return res;
}

// 树状数组：区间查询
ll rangeQuery(int l, int r) {
    if (l > r) return 0;
    return query(r) - query(l - 1);
}

// 更新操作树中的节点，并更新树状数组
void pushupTree(int idx) {
    int l = tree[idx].l, r = tree[idx].r;
    ll old_mav = tree[idx].mav; // 旧的最大值
    tree[idx].mav = max(tree[l].miv, tree[r].miv); // 新的最大值
    tree[idx].miv = min(tree[l].miv, tree[r].miv); // 新的最小值
    // 更新树状数组：位置idx-n对应轮次idx-n
    if (idx > n) {
        update(idx - n, tree[idx].mav - old_mav);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    queue<Node> que;
    int idx = 1;

    // 读入初始序列，初始化叶子节点
    for (int i = 1; i <= n; i++) {
        ll k;
        cin >> k;
        tree[idx].mav = k;
        tree[idx].miv = k;
        tree[idx].idx = idx;
        que.push(tree[idx]);
        idx++;
    }

    // 构建操作树
    while (que.size() > 1) {
        Node x = que.front(); que.pop();
        Node y = que.front(); que.pop();
        tree[idx].idx = idx;
        tree[idx].l = x.idx;
        tree[idx].r = y.idx;
        tree[x.idx].p = idx;
        tree[y.idx].p = idx;
        tree[idx].mav = max(x.miv, y.miv);
        tree[idx].miv = min(x.miv, y.miv);
        que.push(tree[idx]);
        idx++;
    }

    // 初始化轮次结果数组a和树状数组bit
    for (int i = n + 1; i < idx; i++) {
        a[i - n] = tree[i].mav;
    }
    for (int i = 1; i <= n - 1; i++) {
        update(i, a[i]);
    }

    // 处理操作
    while (m--) {
        char op;
        int l, r;
        cin >> op >> l >> r;
        if (op == 'A') {
            // 查询区间[l, r]的和
            cout << rangeQuery(l, r) << "\n";
        } else {
            // 交换操作：交换两个叶子节点的值
            // 注意：这里的l和r是位置索引，对应树中的叶子节点索引
            int leaf1 = l, leaf2 = r;
            // 交换叶子节点的值
            swap(tree[leaf1].mav, tree[leaf2].mav);
            swap(tree[leaf1].miv, tree[leaf2].miv);

            // 更新叶子节点的所有祖先节点
            int p1 = tree[leaf1].p;
            while (p1 != 0) {
                pushupTree(p1);
                p1 = tree[p1].p;
            }
            int p2 = tree[leaf2].p;
            while (p2 != 0) {
                pushupTree(p2);
                p2 = tree[p2].p;
            }
        }
    }

    return 0;
}