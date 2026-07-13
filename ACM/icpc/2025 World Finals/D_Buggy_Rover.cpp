#include <bits/stdc++.h>
using namespace std;

int id(char ch)
{
    if (ch == 'N') return 0;
    if (ch == 'E') return 1;
    if (ch == 'S') return 2;
    return 3;
}

void test()
{
    int r, c;
    cin >> r >> c;

    vector<string> g(r);
    int x = -1, y = -1;
    for (int i = 0; i < r; i++) {
        cin >> g[i];
        for (int j = 0; j < c; j++) {
            if (g[i][j] == 'S') {
                x = i;
                y = j;
            }
        }
    }

    string s;
    cin >> s;

    const string dir = "NESW";
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    vector<string> all;
    string p = dir;
    sort(p.begin(), p.end());
    do {
        all.push_back(p);
    } while (next_permutation(p.begin(), p.end()));

    auto first_dir = [&](const string &ord, int mask) {
        for (char ch : ord) {
            int k = id(ch);
            if (mask >> k & 1) return ch;
        }
        return '?';
    };

    vector<string> possible = all;
    int ans = 0;

    for (char ch : s) {
        int mask = 0;
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (0 <= nx && nx < r && 0 <= ny && ny < c && g[nx][ny] != '#') {
                mask |= 1 << k;
            }
        }

        vector<string> next_possible;
        for (auto &ord : possible) {
            if (first_dir(ord, mask) == ch) {
                next_possible.push_back(ord);
            }
        }

        if (next_possible.empty()) {
            ans++;
            possible = all;
            for (auto &ord : possible) {
                if (first_dir(ord, mask) == ch) {
                    next_possible.push_back(ord);
                }
            }
        }

        possible = next_possible;
        int k = id(ch);
        x += dx[k];
        y += dy[k];
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--) test();
    return 0;
}
