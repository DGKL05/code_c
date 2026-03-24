#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 200000;
const int mod = 998244353;

long long fact[MAXN + 10];

void init() {
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        fact[i] = fact[i - 1] * i % mod;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        sort(a.begin(), a.end(), greater<int>());
        int i_ptr = 0, j_ptr = 0, cnt = 0;
        while (i_ptr < n && j_ptr < n) {
            if (a[i_ptr] > b[j_ptr]) {
                cnt++;
                i_ptr++;
            } else {
                j_ptr++;
            }
        }
        cout<<"cnt = "<<cnt<<"\n";
        long long ans = fact[cnt] * fact[n - cnt] % mod;
        cout << ans << '\n';
    }
    return 0;
}