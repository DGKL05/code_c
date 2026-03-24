#include <iostream>
#include <queue>
#include <vector>
#define sz(v) ((int)(v).size())
#define pb push_back
#define fi first
#define se second
#define MULTI int _T; cin >> _T; while(_T--)
using namespace std;

typedef pair <int, int> pii;

const int N = 2e3 + 5;
const int INF = 0x3f3f3f3f;
template <typename T> bool chkmin(T &x, T y) {return y < x ? x = y, 1 : 0;}
template <typename T> bool chkmax(T &x, T y) {return y > x ? x = y, 1 : 0;}

int n, W;
struct Tri {
	int x, y, siz, w;
	pii verProj() {
		return {x, x + siz};
	}
	pii horProj() {
		return {y, y + siz};
	}
	pii horProj2() {
		// int xb = x + siz;
		// int horOffset = W - xb;
		// return {y + horOffset, y + siz + horOffset};
		return {y - x - siz, y - x};
	}
	int isIntersect(Tri b) {
		auto notIntersect = [](pii u, pii v) {
			return max(u.fi, v.fi) > min(u.se, v.se);
		};
		if (notIntersect(verProj(), b.verProj())) return 0;
		if (notIntersect(horProj(), b.horProj())) return 0;
		if (notIntersect(horProj2(), b.horProj2())) return 0;
		return 1;
	}
} a[N];

vector<int> e[N];
void addedge(int u, int v) {
	e[u].pb(v);
	e[v].pb(u);
}
vector<int> dijkstra(int s) {
	priority_queue<pii> q;
	vector<int> dis(n + 3 + 1, INF);
	vector<int> vis(n + 3 + 1, 0);
	
	dis[s] = 0;
	q.push({0, s});
	while (sz(q)) {
		auto [_, u] = q.top(); q.pop();
		if (chkmax(vis[u], 1) == 0) continue;
		for (int v: e[u]) {
			int w = (u <= n ? a[u].w : 0); 
			if (chkmin(dis[v], dis[u] + w)) q.push({-dis[v], v});
		}
	}
	return dis;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	MULTI {
		cin >> n >> W;
		for (int i = 1;i <= n;++i) {
			int x, y, siz, w;
			cin >> x >> y >> siz >> w;
			a[i] = {x, y, siz, w};
		}

		for (int i = 1;i <= n + 3;++i) {
			e[i].clear();
		}
		for (int i = 1;i <= n;++i) {
			auto [x, y, siz, _] = a[i];
			if (x + siz == W) addedge(i, n + 1);
			if (y == x) addedge(i, n + 2);
			if (y == 0) addedge(i, n + 3);
		}
		for (int i = 1;i <= n;++i) {
			for (int j = i + 1;j <= n;++j) {
				if (a[i].isIntersect(a[j])) {
					addedge(i, j);
				}
			}
		}

		vector<int> disa = dijkstra(n + 1);
		vector<int> disb = dijkstra(n + 2);
		vector<int> disc = dijkstra(n + 3);
		int ans = INF;
		for (int i = 1;i <= n;++i) {
			if ((disa[i] == INF) || (disb[i] == INF) || (disc[i] == INF)) continue;
			chkmin(ans, a[i].w + disa[i] + disb[i] + disc[i]);
		}
		cout << (ans == INF ? -1 : ans) << endl;
	}
}