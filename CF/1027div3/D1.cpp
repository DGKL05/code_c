#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Monster {
    ll x, y;
};

void test() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> v1(n);
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> v1[i].first >> v1[i].second;
        x[i] = v1[i].first;
        y[i] = v1[i].second;
    }
    vector<ll> xx = x;
    sort(xx.begin(), xx.end());
    ll min_x = xx[0];
    ll max_x = xx.back();
    int cnt_min_x = count(xx.begin(), xx.end(), min_x);
    int cnt_max_x = count(xx.begin(), xx.end(), max_x);
    ll min_x2 = min_x;
    for (ll num : xx) {
        if (num > min_x) {
            min_x2 = num;
            break;
        }
    }
    ll max_x2 = max_x;
    for (auto it = xx.rbegin(); it != xx.rend(); ++it) {
        if (*it < max_x) {
            max_x2 = *it;
            break;
        }
    }
    vector<ll> yy = y;
    sort(yy.begin(), yy.end());
    ll min_y = yy[0];
    ll max_y = yy.back();
    int cnt_min_y = count(yy.begin(), yy.end(), min_y);
    int cnt_max_y = count(yy.begin(), yy.end(), max_y);
    ll min_y2 = min_y;
    for (ll num : yy) {
        if (num > min_y) {
            min_y2 = num;
            break;
        }
    }
    ll max_y2 = max_y;
    for (auto it = yy.rbegin(); it != yy.rend(); ++it) {
        if (*it < max_y) {
            max_y2 = *it;
            break;
        }
    }

    ll ans = (max_x - min_x + 1) * (max_y - min_y + 1);
    ll min_num = 1e18;

    for (int i = 0; i < n; ++i) {
        ll xi = v1[i].first;
        ll yi = v1[i].second;

        ll new_min_x = (xi == min_x && cnt_min_x == 1) ? min_x2 : min_x;
        ll new_max_x = (xi == max_x && cnt_max_x == 1) ? max_x2 : max_x;

        ll new_min_y = (yi == min_y && cnt_min_y == 1) ? min_y2 : min_y;
        ll new_max_y = (yi == max_y && cnt_max_y == 1) ? max_y2 : max_y;

        ll t = new_max_x - new_min_x + 1;
        ll t1 = new_max_y - new_min_y + 1;
        if (t * t1 == n - 1) {
            if (t > t1) t++;
            else t1++;
        }
        min_num = min(min_num, t * t1);
    }

    cout << min(ans, min_num) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) test();
    return 0;
}