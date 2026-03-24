#include<bits/stdc++.h>
using namespace std;
using ll =long long;

const int di[3] = {-1, 1, 0};
const int dj[3] = {0, 0, 1};

void test()
{
     int N, M, K;
    cin >> N >> M >> K;
    vector<string> grid(N);
    for (int i = 0; i < N; i++) {
        cin >> grid[i];
    }
    vector<vector<bool>> global_ok(N, vector<bool>(M, false));
    queue<pair<int, int>> q_global;
    global_ok[0][M-1] = true;
    q_global.push({0, M-1});
    const int moves[3][2] = {{-1, 0}, {1, 0}, {0, -1}};
    while (!q_global.empty()) {
        auto [i, j] = q_global.front();
        q_global.pop();
        for (auto [dx, dy] : moves) {
            int ni = i + dx;
            int nj = j + dy;
            if (ni >= 0 && ni < N && nj >= 0 && nj < M && grid[ni][nj] == '0' && !global_ok[ni][nj]) {
                global_ok[ni][nj] = true;
                q_global.push({ni, nj});
            }
        }
    }
    vector<bool> A;
    if (M > 1) {
        A.resize(M-1, false);
        for (int j = 0; j < M-1; j++) {
            for (int i = 0; i < N; i++) {
                if (grid[i][j] == '0') {
                    for (int d : {-1, 0, 1}) {
                        int ni = i + d;
                        if (ni >= 0 && ni < N && grid[ni][j+1] == '0') {
                            A[j] = true;
                            break;
                        }
                    }
                    if (A[j]) break;
                }
            }
        }
    }
    vector<vector<bool>> st_table;
    int L = M - 1;
    if (L > 0) {
        int max_k = floor(log2(L));
        st_table.resize(max_k + 1, vector<bool>(L, false));
        st_table[0] = A;
        for (int k = 1; k <= max_k; k++) {
            int len_seg = 1 << (k - 1);
            for (int i = 0; i + (1 << k) <= L; i++) {
                st_table[k][i] = st_table[k - 1][i] && st_table[k - 1][i + len_seg];
            }
        }
    }
    auto range_and_query = [&](int l, int r) -> bool {
        if (l > r) return true;
        int len = r - l + 1;
        int k = floor(log2(len));
        return st_table[k][l] && st_table[k][r - (1 << k) + 1];
    };
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    queue<pair<int, int>> q;
    bool found_dead_end = false;
    if (grid[0][0] == '0') {
        visited[0][0] = true;
        q.push({0, 0});
    }
    while (!q.empty() && !found_dead_end) {
        auto [i, j] = q.front();
        q.pop();
        if (!global_ok[i][j]) {
            found_dead_end = true;
            break;
        }
        for (int d = 0; d < 3; d++) {
            int ni = i + di[d];
            int nj = j + dj[d];
            if (ni < 0 || ni >= N || nj < 0 || nj >= M || grid[ni][nj] == '1' || visited[ni][nj]) {
                continue;
            }
            int j_view_end = min(j + K, M - 1);
            bool condition_holds = true;
            if (nj == j_view_end) {
                condition_holds = true;
            } else {
                if (nj < M - 1 && nj < j_view_end) {
                    if (L == 0) {
                        condition_holds = true;
                    } else {
                        condition_holds = range_and_query(nj, j_view_end - 1);
                    }
                }
            }
            if (condition_holds) {
                visited[ni][nj] = true;
                q.push({ni, nj});
            }
        }
    }
    cout << (found_dead_end ? "Yes" : "No") << '\n';
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}