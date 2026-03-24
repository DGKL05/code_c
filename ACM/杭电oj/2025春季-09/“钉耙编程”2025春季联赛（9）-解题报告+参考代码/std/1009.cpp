#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cassert>
#define sz(v) ((int)(v).size())
#define pb push_back
#define MULTI int _T; cin >> _T; while(_T--)
using namespace std;

typedef long long ll;

const int N = 1e5 + 5;
const int M = 2e5 + 5;
template <typename T> bool chkmin(T &x, T y) {return y < x ? x = y, 1 : 0;}
template <typename T> bool chkmax(T &x, T y) {return y > x ? x = y, 1 : 0;}

int n;
struct Rect {
	int xl, yl, xr, yr;
	ll area() {
		return 1ll * (yr - yl) * (xr - xl);
	}
} a[N];

struct Proj {
	int id;
	int yl, tr;
};
bool operator < (const Proj &a, const Proj &b) {
	return a.yl < b.yl;
}

vector<int> e[N];
int deg[N];
void addedge(int u, int v) {
	e[u].pb(v);
	deg[v]++;
}

struct SGT {
	struct Node {
		int l, r, lc, rc;
		int mx, tag;
	} t[M * 2];
	int cnt = 0;
	
	#define lc t[u].lc
	#define rc t[u].rc
	#define mid ((t[u].l + t[u].r) / 2)
	
	void pushup(int u) {
		t[u].mx = max(t[lc].mx, t[rc].mx);
	}
	
	void build(int l, int r) {
		int u = ++cnt;
		t[u].l = l, t[u].r = r;
		t[u].mx = t[u].tag = 0;
		if (l != r) {
			lc = cnt + 1, build(l, mid);
			rc = cnt + 1, build(mid + 1, r);
			pushup(u);
		}
	}
	
	void apply(int u, int x) {
		chkmax(t[u].mx, x);
		chkmax(t[u].tag, x);
	}
	
	void pushdown(int u) {
		apply(lc, t[u].tag);
		apply(rc, t[u].tag);
	}
	
	void update(int u, int l, int r, int x) {
		if ((l <= t[u].l) && (t[u].r <= r)) {
			apply(u, x);
		} else {
			pushdown(u);
			if (l <= mid) update(lc, l, r, x);
			if (mid + 1 <= r) update(rc, l, r, x);
			pushup(u);
		}
	}
	
	int query(int u, int l, int r) {
		if ((l <= t[u].l) && (t[u].r <= r)) {
			return t[u].mx;
		} else {
			pushdown(u);
			int ret = 0;
			if (l <= mid) chkmax(ret, query(lc, l, r));
			if (mid + 1 <= r) chkmax(ret, query(rc, l, r));
			return ret;
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	MULTI {
		cin >> n;
		for (int i = 1;i <= n;++i) {
			cin >> a[i].xl >> a[i].yl >> a[i].xr >> a[i].yr;
		}

		set<int> xs;
		map<int, set<Proj>> x2rectl, x2rectr;
		for (int i = 1;i <= n;++i) {
			Proj t = {i, a[i].yl, a[i].yr};
			xs.insert(a[i].xl);
			xs.insert(a[i].xr);
			x2rectl[a[i].xl].insert(t);
			x2rectr[a[i].xr].insert(t);
		}

		set<Proj> cur; 
		for (int i = 1;i <= n;++i) {
			e[i].clear();
			deg[i] = 0;
		}
		for (int x: xs) {
			for (Proj t: x2rectr[x]) { // del rect
				auto it = cur.find(t);
				assert(it != cur.end());
				if ((it != cur.begin()) && (it != (--cur.end()))) {
					auto prev = it; --prev;
					auto succ = it; ++succ;
					addedge(prev -> id, succ -> id);
				}
				cur.erase(it);
			}
			for (Proj t: x2rectl[x]) { // add rect
				auto [it, ok] = cur.insert(t);
				assert(ok);
				if (it != cur.begin()) {
					auto prev = it; --prev;
					addedge(prev -> id, it -> id);
				}
				if (it != (--cur.end())) {
					auto succ = it; ++succ;
					addedge(it -> id, succ -> id);
				}
			}
		}

		queue<int> q;
		vector<int> topo;
		for (int u = 1;u <= n;++u) {
			if (deg[u] == 0) q.push(u);
		}
		while (sz(q)) {
			int u = q.front(); q.pop();
			topo.pb(u);
			for (int v: e[u]) {
				if (--deg[v] == 0) q.push(v);
			}
		}

		ll ans = 0;
		SGT sgt;
		sgt.build(0, M - 1);
		for (int i: topo) {
			int dest_yl = sgt.query(1, a[i].xl, a[i].xr - 1);
			int dest_yr = dest_yl + (a[i].yr - a[i].yl);
			sgt.update(1, a[i].xl, a[i].xr - 1, dest_yr);
			int dy = a[i].yl - dest_yl;
			assert(dy >= 0);
			ans += dy * a[i].area();
		}
		cout << ans << endl;
	}
}