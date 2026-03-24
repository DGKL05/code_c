#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int xx[4]={-1,1,0,0};
int yy[4]={0, 0,-1,1};
int vis[510][510],dis[510][510];
int n,m;
int dij(){ 
    int ans = 1e9;
    priority_queue <pii,vector<pii>,greater<pii>> que;
    for(int i=0;i<n;i++)  {
        if(vis[i][0]==0) {
            que.push({1, i*m});
            dis[i][0]=1;
        }
    }
    
    while(que.size()){
        auto [d,p]=que.top();
        que.pop();
        int ox=p/m,oy=p%m ,x1,y1;  //还原坐标
        if (oy == m - 1) { ans = min(ans, d); continue; }
        if (d > dis[ox][oy]) continue;
        vis[ox][oy] =1;

        for(int  i=0;i<4;i++){
            x1=ox+xx[i]; y1=oy+yy[i];
            if(x1>=0 && x1<n && y1>=0 && y1<m && vis[x1][y1]==0 && d+1 < dis[x1][y1]){
                dis[x1][y1] = d + 1;
                que.push({dis[x1][y1], x1*m+y1});
            }
        }
    }
    return ans;
}

void test(){
    
    cin>>n>>m;
    for(int i=0;i<n;i++)
     for(int j=0;j<m;j++) vis[i][j]=0,dis[i][j]=1e9; //重置访问

    for(int i=0;i<n;i++){
        int k,a;cin>>k;
        while(k--){
            cin>>a;
            vis[i][a-1]=1; //杂草标记1 不可访问
        }
    }
    int ans = 1e9;
    ans = dij();
    
    cout<<ans<<"\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--) {
        test();
    }
    return 0;
}