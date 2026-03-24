#include<bits/stdc++.h>
using namespace std;
using ll = long long;


const int MAXN = 1e5 + 10;
const int MAXM = 2e5 + 10;
int head[MAXN], nxt[MAXM], to[MAXM], w[MAXM];
int cnt = 0; 

void add(int u, int v, int wt) {
    nxt[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
    w[cnt] = wt;
}

struct kkk {
    int x, y, mod;
    bool operator<(kkk k1) const {
        if (y == k1.y) return mod > k1.mod;
        return y > k1.y;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(head, 0, sizeof(head));
    int n, m, V, T;
    cin >> n >> m >> V >> T;
    for (int i = 1; i <= m; i++) {
        int x, y, wt;
        cin >> x >> y >> wt;
        add(x, y, wt);
        add(y, x, wt);
    }
    vector<int> ma(n + 1,-1);
    priority_queue<kkk, vector<kkk>> qu;
    qu.push({T, 1, 0});
    while (qu.size()) {
        auto [x, y, cur_w] = qu.top();
        qu.pop();
        if (ma[x]!=-1) continue;
        ma[x]=y;
        for (int i = head[x]; i; i = nxt[i]) {
            int v = to[i];
            int wt = w[i];
            if (cur_w + wt <= V) {
                qu.push({v, y, cur_w + wt});
            } else {
                qu.push({v, y + 1, wt});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if(ma[i]==-1) cout<<-1<<" \n"[i == n];
        else cout << ma[i] << " \n"[i == n];
    }
    
    return 0;
}