#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
typedef pair<int,int> PII;
void solve(){
	int n;cin>>n;
	int m=sqrt(n);
	while(m*m<n)m++;
	while((m-1)*(m-1)>=n)m--;
	vector<int>ans;
	int mx=m,mn=1;
	while(1){
		mx=min(mx,n);
		for(int i=mx;i>=mn;i--)ans.push_back(i);
		if(mx==n)break;
		mx+=m;
		mn+=m;
	}
	for(int x:ans)cout<<x<<" ";
	cout<<endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T=1;
	//	cin>>T;
	for(int t=1;t<=T;t++){
		solve();
	}
}