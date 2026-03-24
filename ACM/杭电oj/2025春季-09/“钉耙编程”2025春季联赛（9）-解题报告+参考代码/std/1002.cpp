#include <iostream>
#include <vector>
#define sz(v) ((int)(v).size())
#define pb push_back
#define MULTI int _T; cin >> _T; while(_T--)
using namespace std;

typedef long long ll;
template <typename T> bool chkmin(T &x, T y) {return y < x ? x = y, 1 : 0;}
template <typename T> bool chkmax(T &x, T y) {return y > x ? x = y, 1 : 0;}

int n;

vector<int> manacher(vector<int> s0) {
	vector<int> s = {-1};
	for (int val: s0) {
		s.pb(val);
		s.pb(-1);
	}
	int n = sz(s);

	vector<int> d(n);
	for (int i = 0, l = 0, r = -1;i <= n - 1;++i) {
		int k = (i > r) ? 1 : min(d[l + r - i], r - i + 1);
		while ((0 <= i - k) && (i + k <= n - 1) && (s[i - k] + s[i + k] == s[i - k + 2] + s[i + k - 2])) {
			k++;
		}
		d[i] = k--;
		if (i + k > r) {
			l = i - k;
			r = i + k;
		}
	}
	return d;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	MULTI {
		cin >> n;
		vector<int> a(n);
		for (int i = 0;i <= n - 1;++i) {
			cin >> a[i];
		}

		vector<int> d = manacher(a);
		ll ans = 0;
		for (int r: d) {
			ans += r / 2;
		}
		cout << ans << "\n";
	}
}