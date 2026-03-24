#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200000;
vector<int> divisors_of_d[MAX_N + 1];

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int g = 1; g <= MAX_N; g++) {
        for (int d = 2 * g; d <= MAX_N; d += g) {
            divisors_of_d[d].push_back(g);
        }
    }

    int t;
    cin >> t;
    vector<int> cnt(MAX_N + 1, 0);
    vector<int> max_cnt(MAX_N + 1, 0);
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        set<int> modified_d_set, modified_g_set;
        int G = 0;
        for (int i = 0; i < n; i++) {
            int x = a[i];
            G = gcd(G, x);
            for (int d = 1; d * d <= x; d++) {
                if (x % d == 0) {
                    if (d <= n) {
                        if (cnt[d] == 0) {
                            modified_d_set.insert(d);
                        }
                        cnt[d]++;
                        for (int g : divisors_of_d[d]) {
                            if (cnt[d] > max_cnt[g]) {
                                if (max_cnt[g] == 0) {
                                    modified_g_set.insert(g);
                                }
                                max_cnt[g] = cnt[d];
                            }
                        }
                    }
                    int d2 = x / d;
                    if (d2 <= n && d2 != d) {
                        if (cnt[d2] == 0) {
                            modified_d_set.insert(d2);
                        }
                        cnt[d2]++;
                        for (int g : divisors_of_d[d2]) {
                            if (cnt[d2] > max_cnt[g]) {
                                if (max_cnt[g] == 0) {
                                    modified_g_set.insert(g);
                                }
                                max_cnt[g] = cnt[d2];
                            }
                        }
                    }
                }
            }
            cout << max_cnt[G] << " ";
        }
        cout << "\n";
        for (int d : modified_d_set) {
            cnt[d] = 0;
        }
        for (int g : modified_g_set) {
            max_cnt[g] = 0;
        }
    }
    return 0;
}