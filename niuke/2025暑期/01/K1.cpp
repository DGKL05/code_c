#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1200005;


void test() {

    int n;
    cin >> n;

    vector<vector<int>> e(n + 1);
    vector<unordered_map<int, int>> mp(n + 1);

    for (int u = 1; u <= n; u++) {
        int d;
        cin >> d;
        for (int j = 0; j < d; j++) {
            int v;
            cin >> v;
            e[u].push_back(v);
        }
    }

    for (int u = 1; u <= n; u++) {
        for (int j = 0; j < e[u].size(); j++) {
            int v = e[u][j];
            mp[u][v] = j;
        }
    }

    int tot = 0;
    vector<vector<int>> eid(n + 1);
    map<pair<int, int>, int> emap;
    int tot2 = 0;
    vector<int> eu(N, -1);

    for (int u = 1; u <= n; u++) {
        eid[u].resize(e[u].size());
        for (int i = 0; i < e[u].size(); i++) {
            int v = e[u][i];
            eid[u][i] = tot;
            int a = min(u, v);
            int b = max(u, v);
            pair<int, int> key = {a, b};
            if (emap.find(key) == emap.end()) {
                emap[key] = tot2++;
            }
            int uid = emap[key];
            eu[tot] = uid;
            tot++;
        }
    }

    vector<int> nxt(N, -1);
    for (int u = 1; u <= n; u++) {
        for (int i = 0; i < e[u].size(); i++) {
            int id1 = eid[u][i];
            int v = e[u][i];
            int j = mp[v][u];
            int nj = (j + 1) % e[v].size();
            int id2 = eid[v][nj];
            nxt[id1] = id2;
        }
    }

    vector<int> deg(N, 0);
    for (int i = 0; i < tot; i++) {
        int v = nxt[i];
        if (v != -1) deg[v]++;
    }

    vector<vector<int>> re(N);
    for (int i = 0; i < tot; i++) {
        int v = nxt[i];
        if (v != -1) re[v].push_back(i);
    }

    queue<int> q;
    for (int i = 0; i < tot; i++) {
        if (deg[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        int v = nxt[u];
        if (v != -1) {
            deg[v]--;
            if (deg[v] == 0) q.push(v);
        }
    }

    vector<int> cid(N, -1);
    vector<int> ccnt;
    vector<bool> vis(N, false);
    vector<int> dis(N, -1);
    int tot3 = 0;

    for (int i = 0; i < tot; i++) {
        if (deg[i] > 0 && !vis[i]) {
            set<int> s;
            vector<int> cyc;
            int cur = i;
            while (!vis[cur]) {
                vis[cur] = true;
                cyc.push_back(cur);
                s.insert(eu[cur]);
                cur = nxt[cur];
            }
            for (int u : cyc) {
                cid[u] = tot3;
                dis[u] = 0;
            }
            ccnt.push_back(s.size());
            tot3++;
        }
    }

    vector<int> cid2(N, -1);
    queue<int> q2;
    for (int i = 0; i < tot; i++) {
        if (dis[i] == 0) {
            q2.push(i);
            cid2[i] = cid[i];
        }
    }
    while (!q2.empty()) {
        int u = q2.front(); q2.pop();
        for (int pre : re[u]) {
            if (dis[pre] == -1) {
                dis[pre] = dis[u] + 1;
                cid2[pre] = cid2[u];
                q2.push(pre);
            }
        }
    }

    vector<int> ans(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (e[i].empty()) {
            ans[i] = 0;
        } else {
            int id0 = eid[i][0];
            if (cid2[id0] == -1) {
                ans[i] = dis[id0];
            } else {
                ans[i] = dis[id0] + ccnt[cid2[id0]];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test();
    return 0;
}
