#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	ll jl = 1e16;
	vector<ll> v; 
}c[30];
ll a[30][30], b[30][30], mi = 1e16, n;
vector<int> sx;
void dfs(int k, ll jl){
	int i;
	if(k == n){
		mi = jl;
		return ;
	}
	for(i = 1; i <= n; i++){
		b[k][i] = 1;
		if(a[k][i] != 0 && c[i].jl > c[k].jl + a[k][i]){
			c[i].v = c[k].v;
			c[i].v.push_back(i);
			c[i].jl = c[k].jl + a[k][i];
			dfs(i, c[k].jl + a[k][i]);
		}
		b[k][i] = 0;
	}
	
}

int main(){

    //cout<<"TEST:\n";
    
	int i, j;
	cin >> n;
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
    //cout<<a[1][15]<<' '<<a[15][20]<<"\n";

	if(n == 1){
		cout << 0 << endl << 1;
		return 0;
	}
	c[1].jl = 0;
	c[1].v.push_back(1);
	dfs(1, 0);
	cout << "minlong=" << mi << endl;
    i=1;
    for(auto it:c[n].v){
		cout << it << ' ';
        // if(it!=1) cout<<a[i][it]<<' ';
        // i=it;
	}
    cout<<"\n";
	for(auto it:c[n].v){
		// cout << it << ' ';
        if(it!=1) cout<<i<<"->"<<it<<" = "<<a[i][it]<<'\n';
        i=it;
	}
	
	return 0;
}