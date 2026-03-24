#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int n, a[N], b[N], pre[N*N], d[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};//方向数组 
bool vis[N][N];
int p(int x, int y) {//计算点(x,y)的对应的编号 
	return (x-1)*n+y-1;
}
bool check() {//判断是否符合题意 
	for (int i = 1; i <= n; ++i) if (a[i] || b[i]) return 0;//只要有一个点漏了，就不行 
	return 1;
}
void print(int x) {//输出路径 
	if (pre[x] == -1) return;//边界，防止无限递归 
	print(pre[x]);
	cout << x << ' ';//回溯时输出，这样路径就是正着的了 
}
void dfs(int x, int y) {//搜索 
	if (x == n && y == n) {//边界 
		if (check()) {
			cout << 0 << ' ';
			print(n*n-1);
			exit(0);
		}
		return;
	}
	for (int i = 0; i < 4; ++i) {
		int xx = x+d[i][0], yy = y+d[i][1];
		if (xx < 1 || xx > n || yy < 1 || yy > n) continue;//越界 
		if (a[yy] >= 1 && b[xx] >= 1 && !vis[xx][yy]) {//可行性剪枝加避免重复 
			--a[yy], --b[xx];
			vis[xx][yy] = 1;
			pre[p(xx, yy)] = p(x, y);//记录前驱 
			dfs(xx, yy);
			vis[xx][yy] = 0;//回溯 
			++a[yy], ++b[xx];
		}
	}
}
int main(){
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) cin >> b[i];
	--a[1], --b[1], vis[1][1] = 1, pre[0] = -1;//初始化 
	dfs(1, 1);
	return 0;
}