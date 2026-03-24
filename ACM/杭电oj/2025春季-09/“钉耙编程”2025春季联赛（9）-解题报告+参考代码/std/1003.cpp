#include <bits/stdc++.h>
#define REP(i,l,r) for (auto i=l; i<=r; i++)
#define REV(i,l,r) for (auto i=l; i>=r; i--)
#define endl "\n"

using namespace std;
using i64 = long long;

static inline void solve() {
	int n;
	cin >> n;

	vector<int> X(n + 1), Y(n + 1);
	vector<array<int, 2>> pt(n + 1);

	map<array<int, 2>, map<i64, int>> mp;

	REP(i, 1, n) {
		int x, y;
		cin >> x >> y;
		x *= 2, y *= 2;
		pt[i] = {x, y};
	}

	sort(pt.begin()+1, pt.begin()+n+1);

	REP(i, 1, n) {
		REP(j, 1, n) {
			if (i == j) continue;
			auto [x1, y1] = pt[i];
			auto [x2, y2] = pt[j];
			int u = y1 - y2;
			int v = x2 - x1;
			if (u > 0 && v >= 0) {
				if (lower_bound(pt.begin()+1, pt.begin()+n+1, array<int, 2> {x1+u, y1+v})
					!= upper_bound(pt.begin()+1, pt.begin()+n+1, array<int, 2> {x1+u, y1+v})) {
					if (lower_bound(pt.begin()+1, pt.begin()+n+1, array<int, 2> {x2+u, y2+v})
						!= upper_bound(pt.begin()+1, pt.begin()+n+1, array<int, 2> {x2+u, y2+v})) {
						int xx = (x1 + x2 + u) / 2;
						int yy = (y1 + y2 + v) / 2;
						mp[{xx, yy}][1ll * u * u + 1ll * v * v] ++;
					}
				}
			}
		}
	}

	i64 ans = 0;
	for (auto &[mid, v] : mp) {
		// auto [xx, yy] = mid; cout << xx << " " << yy << " " << v.size() << endl;
		for (auto [uv, num] : v) {
			// num /= 4;
			// cout << "!!!!! " << uv << " " << num << endl;
			ans += 1ll * (num) * (num-1) / 2;
		}
	}

	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tt;
	cin >> tt;

	while (tt--) {
		solve();
	}
}
