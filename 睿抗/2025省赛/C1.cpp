#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, s;
    cin >> n >> m >> s;

    // 存储水平边和垂直边的存在状态
    vector<vector<bool>> hor(n + 1, vector<bool>(m + 1, false));
    vector<vector<bool>> ver(n + 1, vector<bool>(m + 1, false));
    
    // 存储格子是否已经被计分
    vector<vector<bool>> box_created(n + 1, vector<bool>(m + 1, false));
    
    // 存储有问题的步骤编号
    vector<int> wszbzwcrle;
    
    int current_player = 0;  // 0: 小A的回合，1: 小B的回合
    int scoreA = 0, scoreB = 0;  // 小A和小B的得分

    for (int step = 1; step <= s; step++) {
        int p, x1, y1, x2, y2;
        cin >> p >> x1 >> y1 >> x2 >> y2;

        // 检查两点是否相邻
        if (!((x1 == x2 && abs(y1 - y2) == 1) || (y1 == y2 && abs(x1 - x2) == 1))) {
            wszbzwcrle.push_back(step);
            continue;
        }

        // 检查玩家顺序是否正确
        if (p != 1 - current_player) {
            wszbzwcrle.push_back(step);
            continue;
        }

        int completed = 0;  // 本次操作完成的格子数量

        if (x1 == x2) {  // 水平边
            int y_min = min(y1, y2);
            int x = x1;

            // 检查边是否已存在
            if (hor[x][y_min]) {
                wszbzwcrle.push_back(step);
                continue;
            }

            // 标记边已存在
            hor[x][y_min] = true;

            // 检查上方格子
            if (x >= 2) {
                int i = x - 1, j = y_min;
                if (j >= 1 && j <= m - 1 && !box_created[i][j]) {
                    if (hor[i][j] && hor[i + 1][j] && ver[i][j] && ver[i][j + 1]) {
                        completed++;
                        box_created[i][j] = true;
                    }
                }
            }

            // 检查下方格子
            if (x <= n - 1) {
                int i = x, j = y_min;
                if (j >= 1 && j <= m - 1 && !box_created[i][j]) {
                    if (hor[i][j] && hor[i + 1][j] && ver[i][j] && ver[i][j + 1]) {
                        completed++;
                        box_created[i][j] = true;
                    }
                }
            }
        } else {  // 垂直边
            int x_min = min(x1, x2);
            int y = y1;

            // 检查边是否已存在
            if (ver[x_min][y]) {
                wszbzwcrle.push_back(step);
                continue;
            }

            // 标记边已存在
            ver[x_min][y] = true;

            // 检查左侧格子
            if (y >= 2) {
                int i = x_min, j = y - 1;
                if (i >= 1 && i <= n - 1 && !box_created[i][j]) {
                    if (hor[i][j] && hor[i + 1][j] && ver[i][j] && ver[i][j + 1]) {
                        completed++;
                        box_created[i][j] = true;
                    }
                }
            }

            // 检查右侧格子
            if (y <= m - 1) {
                int i = x_min, j = y;
                if (i >= 1 && i <= n - 1 && !box_created[i][j]) {
                    if (hor[i][j] && hor[i + 1][j] && ver[i][j] && ver[i][j + 1]) {
                        completed++;
                        box_created[i][j] = true;
                    }
                }
            }
        }

        // 更新得分和玩家回合
        if (completed > 0) {
            if (current_player == 0) {
                scoreA += completed;
            } else {
                scoreB += completed;
            }
        } else {
            current_player = 1 - current_player;
        }
    }

    // 输出有问题的步骤或-1
    if (wszbzwcrle.empty()) {
        cout << "-1" << endl;
    } else {
        sort(wszbzwcrle.begin(), wszbzwcrle.end());
        for (int i = 0; i < wszbzwcrle.size(); i++) {
            if (i > 0) cout << " ";
            cout << wszbzwcrle[i];
        }
        cout << endl;
    }

    // 输出获胜者和得分
    if (scoreA >= scoreB) {
        cout << "0 " << scoreA << endl;
    } else {
        cout << "1 " << scoreB << endl;
    }

    return 0;
}