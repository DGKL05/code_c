#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;
const int M = 2e3 + 10;
const int N = 40;

struct Edge{
   
	int to,val;
	int nxt;
}edges[M];
int head[N],idx = 0;
void add(int u, int v, int c)
{
   
	edges[idx] = {
   v,c,head[u]}, head[u] = idx++;
	edges[idx] = {
   u,c,head[v]}, head[v] = idx++;
}

int dp[N][500];
int f[500];
map<string, int> mp;
typedef pair<int,int> pii;
priority_queue<pii, vector<pii>, greater<pii>> q;
bool vis[N];

void dij(int s)
{
	memset(vis,0,sizeof(vis));
	while(q.size()){
		int u = q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = head[u];~i;i = edges[i].nxt){
			int v = edges[i].to;
			int cost = edges[i].val;
			if(dp[v][s] > dp[u][s] + cost){
				dp[v][s] = dp[u][s] + cost;
				q.push({dp[v][s],v});
			}
		}
	}
}

bool check(int s)
{
	for(int i = 0;i < 4;++i){
		int x = s >> (i * 2) & 1;
		int y = s >> (i * 2 + 1) & 1;
		if(x ^ y) return 1;
	}
	return 0;
}

int main()
{
    // cout<<(1 << 8)<<"\n";
	memset(head,-1,sizeof(head));
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;++i){
		string s;
		cin >> s;
		mp[s] = i;
	}
	for(int i = 0;i < m;++i){
		string a, b;
		int cost;
		cin >> a >> b >> cost;
		add(mp[a],mp[b],cost);
	}
	memset(dp,0x3f,sizeof(dp));
	for(int i = 0;i < 8;++i) {
		string s;
		cin>>s;
		dp[mp[s]][1 << i] = 0;
	}

	for(int s = 0; s < (1 << 8);++s){
		for(int i = 1;i <= n;++i){
			for(int subs = s & (s-1);subs;subs = s & (subs - 1)){
				dp[i][s] = min(dp[i][s], dp[i][subs] + dp[i][s ^ subs]);
			}
			if(dp[i][s] != inf) q.push({dp[i][s],i});
		}
		dij(s);
	}

	memset(f,0x3f,sizeof(f));
	for(int s = 0;s < (1 << 8);++s){
		if(check(s)) continue;
		for(int i = 1;i <= n;++i) f[s] = min(dp[i][s],f[s]);
		for(int subs = s & (s-1);subs;subs = s & (subs - 1)){
			if(check(subs)) continue;
			f[s] = min(f[subs] + f[s ^ subs], f[s]);	
		}
	}
	printf("%d\n",f[(1 << 8) - 1]);  
	return 0;
}
