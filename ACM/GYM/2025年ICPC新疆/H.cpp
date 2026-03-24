#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const int N=22;
int n,m,ans=N; 
int w[N];
 
void dfs(int u,int v,int res){
    if(res>=ans) return;
    if(v+1==(1<<n)){
        ans=res;
        return;
    }
    if(u>=n) return;
    dfs(u+1,v,res);
    dfs(u+1,v|w[u],res+1);
}

void test()
{
    cin>>n>>m;
    for(int i=0,v;i<m;++i){
        cin>>v;
        while(v--){
            int x;
            cin>>x;
            w[i]|=1<<(x-1);
        }
    }
    dfs(0,0,0);
    if(ans==N) cout<<-1;
    else cout<<ans;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}
