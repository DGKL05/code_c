#include <iostream>
#include <numeric>
#include <vector>
#define pb push_back
#define MULTI int _T; cin >> _T; while(_T--)
using namespace std;

const int N = 1e5 + 5;

int n, m;
vector<int> e[N];

struct DSU {
	int sz;
	int fa[N];
	void init(int n) {
		sz = n;
		iota(fa, fa + n + 1, 0);
	}
	int getfa(int x) {
		return x == fa[x] ? x : fa[x] = getfa(fa[x]);
	}
	void merge(int x, int y) {
		x = getfa(x);
		y = getfa(y);
		fa[x] = y;
	}
} dsu;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	MULTI {
		cin >> n >> m;
		for (int i = 0;i <= n;++i) {
			e[i].clear();
		}
		for (int i = 1;i <= m;++i) {
			int u, v;
			cin >> u >> v;
			if (u > v) swap(u, v);
			e[v].pb(u);
		}

		int succ = 1;
		dsu.init(n);
		for (int v = 1;v <= n;++v) {
			for (int u: e[v]) {
				dsu.merge(u, v);
			}
			if (dsu.getfa(v) != dsu.getfa(0)) {
				succ = 0;
				break;
			}
		}
		cout << succ << "\n";
	}
}