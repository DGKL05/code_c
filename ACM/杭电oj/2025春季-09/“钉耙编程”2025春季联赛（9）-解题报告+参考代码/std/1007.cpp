#include <iostream>
#define MULTI int _T; cin >> _T; while(_T--)
using namespace std;

const int N = 1e5 + 5;
template <typename T> bool chkmin(T &x, T y) {return y < x ? x = y, 1 : 0;}
template <typename T> bool chkmax(T &x, T y) {return y > x ? x = y, 1 : 0;}

int n;
int a[N], idx[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	MULTI {
		cin >> n;
		for (int i = 1;i <= n;++i) {
			cin >> a[i];
			idx[a[i]] = i;
		}

		int ans = 0;
		for (int l, r = 1;r <= n;++r) {
			if ((r == 1) || (idx[r - 1] > idx[r])) l = r;
			chkmax(ans, r - l + 1);
		}
		cout << n - ans << endl;
	}
}