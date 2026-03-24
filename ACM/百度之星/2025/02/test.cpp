#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        string s, t;
        cin >> n >> m;
        cin >> s;
        cin >> t;

        if (t[0] == '0') {
            int k = -1;
            for (int i = 0; i < m; i++) {
                if (t[i] == '1') {
                    k = i;
                    break;
                }
            }
            if (k == -1) {
                bool all0 = true;
                for (char c : s) {
                    if (c != '0') {
                        all0 = false;
                        break;
                    }
                }
                if (all0) {
                    cout << 0 << endl;
                } else {
                    cout << -1 << endl;
                }
                continue;
            } else {
                bool valid = true;
                for (int i = 0; i < k; i++) {
                    if (i >= n) break;
                    if (s[i] != '0') {
                        valid = false;
                        break;
                    }
                }
                if (!valid) {
                    cout << -1 << endl;
                    continue;
                }
                s = s.substr(k);
                t = t.substr(k);
                n = s.length();
                m = t.length();
            }
        }

        vector<int> cur(n);
        for (int i = 0; i < n; i++) {
            cur[i] = s[i] - '0';
        }

        int ans = 0;
        for (int i = 0; i <= n - m; i++) {
            if (cur[i] == 1) {
                ans++;
                for (int j = 0; j < m; j++) {
                    if (t[j] == '1') {
                        cur[i + j] ^= 1;
                    }
                }
            }
        }

        bool all0 = true;
        for (int i = 0; i < n; i++) {
            if (cur[i] != 0) {
                all0 = false;
                break;
            }
        }

        if (!all0) {
            cout << -1 << endl;
        } else {
            cout << ans << endl;
        }
    }
    return 0;
}