#include<bits/stdc++.h>
using namespace std;
using ll =long long;

const int N = 1e6 + 5, inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f, mod = 998244353;
int son[N][26], idx = 1;
ll mp[26][26], cnt[N][26], ini;
 
void insert(string s){
	int cur = 0;
	for(int i = 0; i < s.size(); ++ i){
		if(!son[cur][s[i] - 'a']) son[cur][s[i] - 'a'] = idx ++ ;
		for(int j = 0; j < 26; ++ j){
			if(j == s[i] - 'a') continue;
			mp[s[i] - 'a'][j] += cnt[cur][j];
		}
		++ cnt[cur][s[i] - 'a'];
		cur = son[cur][s[i] - 'a'];
	}
	for(int i = 0; i < 26; ++ i) ini += cnt[cur][i];
	return ;
}
 
void test(){
	int n, q;
	string s;
	cin >> n >> q;
	for(int i = 0; i < n; ++ i){
		cin >> s;
		insert(s);
	}
	// for(int i=0;i<10;i++){
	// 	for(int j=0;j<10;j++){
	// 		cout<<son[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }
    // cout<<idx<<"\n";
	for(int i = 0; i < q; ++ i){
		cin >> s;
		ll ans = ini;
		for(int i = 0; i < 26; ++ i){
			for(int j = i + 1; j < 26; ++ j){
				ans += mp[s[i] - 'a'][s[j] - 'a'];
                // cout<<ans<<" ";
			}
		}
		cout << ans << '\n';
	}
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