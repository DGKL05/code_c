#include <iostream>
#include <cstring>
#define MULTI int _T; cin >> _T; while(_T--)
#define sqr(x) ((x) * (x))
using namespace std;

typedef long long ll;

const int N = 105;
const ll INFF = 0x3f3f3f3f3f3f3f3f;
template <typename T> bool chkmin(T &x, T y) {return y < x ? x = y, 1 : 0;}
template <typename T> bool chkmax(T &x, T y) {return y > x ? x = y, 1 : 0;}

ll t, n, m;
ll a[N];
ll dp[N][N][N];

int main() {
	MULTI {
		cin >> t >> n >> m;
		for (int i = 1;i <= n - 1;++i) {
			cin >> a[i];
		}

		memset(dp, 0x3f, sizeof dp);
		dp[0][0][0] = 0;
		for (int cur = 0;cur <= n * t;++cur) for (int lst = 0;lst <= cur;++lst) {
			for (int i = 1;i <= n - 1;++i) {
				ll cnt_op = abs(a[i] - cur);
				ll delta = sqr(cur - lst);
				if (i == n - 1) delta += sqr(n * t - cur);
				for (int j = cnt_op;j <= m;++j) {
					chkmin(dp[cur][i][j], dp[lst][i - 1][j - cnt_op] + delta);
				}
			}
		}

		ll ans = INFF;
		for (int cur = 0;cur <= n * t;++cur) {
			for (int j = 0;j <= m;++j) {
				chkmin(ans, dp[cur][n - 1][j]);
			}
		}
		cout << ans << endl;
	}
}