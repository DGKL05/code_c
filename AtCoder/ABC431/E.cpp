#include<bits/stdc++.h>
using namespace std;
using ll =long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

struct State {
    int cost;
    int x;
    int y;
    int dir;
};

void test() {
    int h, w;
    cin >> h >> w;
    vector<string> grid(h);
    for (int i = 0; i < h; i++) {
        cin >> grid[i];
    }

    // 初始化dp数组为非常大的数
    vector<vector<vector<int>>> dp(h, vector<vector<int>>(w, vector<int>(4, INT_MAX)));

    deque<State> dq;
    // 初始状态：从(0, -1)向右移动到(0, 0)
    dq.push_back({0, 0, -1, 1});

    while (!dq.empty()) {
        State s = dq.front();
        dq.pop_front();
        int nx = s.x + dx[s.dir];
        int ny = s.y + dy[s.dir];

        // 检查新坐标是否在网格范围内
        if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;

        // 遍历四个可能的新方向
        for (int ndir = 0; ndir < 4; ndir++) {
            // 跳过与当前方向相反的方向
            if ((s.dir ^ ndir) == 2) {
                continue;
            }

            // 获取当前网格字符对应的值
            char c_char = grid[nx][ny];
            int val;
            if (c_char == 'A') {
                val = 0;
            } else if (c_char == 'B') {
                val = 1;
            } else if (c_char == 'C') {
                val = 3;
            } else {
                val = 0; // 默认值，但题目保证只有A,B,C
            }

            // 检查是否需要旋转（即方向是否符合）
            int add = 0;
            if ((s.dir ^ ndir) != val) {
                add = 1;
            }

            int new_cost = s.cost + add;

            // 如果新代价更小，则更新dp状态
            if (new_cost < dp[nx][ny][ndir]) {
                dp[nx][ny][ndir] = new_cost;
                State next_state = {new_cost, nx, ny, ndir};
                if (add == 0) {
                    dq.push_front(next_state);
                } else {
                    dq.push_back(next_state);
                }
            }
        }
    }

    // 找出终点四个方向（上一步的方向）的最小代价
    int ans = *min_element(dp[h-1][w-1].begin(), dp[h-1][w-1].end());
    cout << (ans == 0 ? 0 : ans+1 ) << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}