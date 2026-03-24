#include <iostream>
using namespace std;

typedef long long LL;

LL compute_sum_row(LL m, LL L) {
    if (L == 0) return 0;
    LL divisor = L + 1;
    LL quotient = m / divisor;
    LL remainder = m % divisor;
    return quotient * L + remainder;
}

bool is_possible(LL n, LL m, LL k, LL L) {
    LL sum_row = compute_sum_row(m, L);
    LL total = n * sum_row;
    return total >= k;
}

LL solve(LL n, LL m, LL k) {
    if (k == 0) return 0;
    LL left = 1;
    LL right = m;
    LL answer = m;
    while (left <= right) {
        LL mid = (left + right) / 2;
        if (is_possible(n, m, k, mid)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        LL n, m, k;
        cin >> n >> m >> k;
        cout << solve(n, m, k) << '\n';
    }
    return 0;
}