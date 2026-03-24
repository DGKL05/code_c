#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n, m, k;
    cin >> n >> m >> k;
    bool ok = 0;
    vector<vector<char>> c(n + 1, vector<char> (m + 1));
    vector<vector<int>> vis(n + 1, vector<int> (m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c[i][j];
        }
    }
    auto bfs1 = [&]() -> void {
        queue<pair<int, int>> q;
        q.push({1, m});
        int dx[3] = {0, 1, -1}, dy[3] = {-1, 0, 0};
        while (q.size()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 3; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (ny < 1 || nx > n || nx < 1 || vis[nx][ny] || c[nx][ny] == '1') continue;
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    };
    auto bfs2 = [&]() -> void {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({1, 1});
        vis[1][1] = 2;
        int dx[3] = {0, 1, -1}, dy[3] = {1, 0, 0};
        while (q.size()) {
            auto [y, x] = q.top();
            q.pop();
            for (int i = 0; i < 3; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (ny > m || nx > n || nx < 1 || c[nx][ny] == '1') continue;
                if (vis[nx][ny] == 0) {
                    if (k == 1) {
                        ok = 1;
                        return;
                    }
                    vis[nx][ny] = 2;
                    queue<pair<int, int>> qq;
                    qq.push({nx, ny});
                    while (qq.size()) {
                        auto [ux, uy] = qq.front();
                        qq.pop();
                        for (int j = 0; j < 3; j++) {
                            int nnx = ux + dx[j], nny = uy + dy[j];
                            if (nny > m || nnx > n || nnx < 1 || vis[nnx][nny] == 2 || c[nnx][nny] == '1') continue;
                            if (vis[nnx][nny] == 0) {
                                vis[nnx][nny] = 2;
                                qq.push({nnx, nny});
                                int dif = nny - ny + 1;
                                if (dif >= k) {
                                    ok = 1;
                                    return;
                                }
                            } 
                        }
                    }
                }
                if (vis[nx][ny] == 1) {
                    q.push({ny, nx});
                    vis[nx][ny] = 2;
                }
            }
        }
    };
    bfs1();
    bfs2();
    if (ok) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}