#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

void test() {
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> a(n);
    bool has_one = false;
    int first_one = -1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 1) {
            has_one = true;
            if (first_one == -1) {
                first_one = i;
            }
        }
    }
    if (!has_one) {
        cout << "-1\n";
        return;
    }
    if (x == 0) {
        bool all_one = true;
        for (ll num : a) {
            if (num == 0) {
                all_one = false;
                break;
            }
        }
        if (all_one) {
            for (int i = 0; i < n-1; ++i) {
                cout << "1 ";
            }
            cout << "\n";
        } else {
            cout << "-1\n";
        }
        return;
    }
    if (first_one < x) {
        for (int i = 0; i < x; ++i) {
            cout << "0 ";
        }
        for (int i = 0; i < y; ++i) {
            cout << "1 ";
        }
        cout << "\n";
        return;
    }
    int last_one = -1;
    for (int i = n-1; i >= 0; --i) {
        if (a[i] == 1) {
            last_one = i;
            break;
        }
    }
    if (last_one >= n - x) {
        for (int i = 0; i < y; ++i) {
            cout << "1 ";
        }
        for (int i = 0; i < x; ++i) {
            cout << "0 ";
        }
        cout << "\n";
        return;
    }
    if (x >= 2) {
        vector<char> ops(n-1, '1');
        if (first_one > 0) {
            ops[first_one - 1] = '0';
            x--;
        }
        if (first_one < n-1) {
            ops[first_one] = '0';
            x--;
        }
        for (int i = 0; i < n-1 && x > 0; ++i) {
            if (ops[i] == '1') {
                ops[i] = '0';
                x--;
            }
        }
        for (char c : ops) {
            cout << c<<" ";
        }
        cout << "\n";
        return;
    }
    cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        test();
    }
    return 0;
}