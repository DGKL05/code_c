#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int base = 2000;
const int arraySize = 4005;
void test() {
    int n;
    cin >> n;
    vector<int> p(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    ll ans = 0;
    for (int pos = 1; pos <= n; pos++) {
        vector<ll> leftSum(arraySize, 0);
        vector<ll> rightSum(arraySize, 0);
        leftSum[base] = pos;
        rightSum[base] = pos;
        int d = 0;
        for (int i = pos-1; i >= 1; i--) {
            if (p[i] < p[pos]) {
                d++;
            } else {
                d--;
            }
            leftSum[d + base] += i;
        }
        d = 0;
        for (int j = pos+1; j <= n; j++) {
            if (p[j] < p[pos]) {
                d++;
            } else {
                d--;
            }
            rightSum[d + base] += j;
        }
        ll total = 0;
        for (int d_val = -2000; d_val <= 2000; d_val++) {
            total += leftSum[d_val + base] * rightSum[-d_val + base];
        }
        ans += 1LL * p[pos] * total;
    }
    cout << ans << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) test();
    return 0;
}