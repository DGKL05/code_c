#include<bits/stdc++.h>
using namespace std;
using ll =long long;

const int N = 3e3 + 5, inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f, mod = 998244353;
int n, k, dp[N][N][2];
vector<int> p[N];

void test()
{
	cin >> n >> k;
	int sum = 0;
	ll ans=0;
	for(int i = 1; i <= n; ++ i){
		int c, t;
		cin >> c;
		for(int j = 0; j < c; ++ j){
			cin >> t;
			p[i].push_back(t);
		}
		ans+=p[i][c-1];
		sum += c;
	}
	if(sum <= k) {
		cout << ans << '\n';
		return ;
	}
	// mem(dp, -inf);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            dp[i][j][0] = -inf;
            dp[i][j][1] = -inf;
        }
    }
	dp[0][0][0] = 0;
	for(int i = 1; i <= n; ++ i){
		for(int j = 0; j <= k; ++ j){
			dp[i][j][0] = dp[i - 1][j][0];
			dp[i][j][1] = dp[i - 1][j][1];
			int c = p[i].size();
			if(j >= c){// 完全选择时
				dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j - c][0] + p[i].back());
				dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - c][1] + p[i].back());
			}
			for(int l = 1; l <= j && l < c; ++ l){// 不完全选择时
				dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - l][0] + p[i][l - 1]);
				// if(i == 5) cout<<j-l<<" "<<dp[i-1][j-l][0]<<"\n";
			}
		}
	}
	if(sum <= k) cout << ans << '\n';
	else cout << max(dp[n][k][0], dp[n][k][1]) << '\n';
	return ;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}