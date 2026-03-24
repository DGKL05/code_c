#include<bits/stdc++.h>
using namespace std;
using ll =long long;

const int N = 105;
bool arr[N][N];
bool fa[N][N];
int dp[N][N];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int en_x=0;int en_y=0;
int n;
int m;

int bfs(int x,int y)
{
    //cout<<x<<' '<<y<<' '<<en_x<<' '<<en_y<<"\n";
    //cout<<n<<' '<<m<<'\n';
    queue<pair<int,int>>q1;
    q1.push({x,y});
    dp[x][y]=0;
    fa[x][y]=true;
    while(q1.size()){
        pair<int,int>p1=q1.front();
        q1.pop();
        int x1=p1.first;int y1=p1.second;
        if(x1==en_x && y1==en_y) return dp[x1][y1];
        fa[x1][y1]=true;
        for(int i=0;i<4;i++){
            int x2 = x1+dx[i];int y2 = y1+dy[i];
            if(x2<0||x2>=n||y2<0||y2>=m) continue;
            if(fa[x2][y2]) continue;
            if(!arr[x2][y2]) continue;
            //cout<<"x2 = "<<x2<<" y2 = "<<y2<<"\n";
            dp[x2][y2]=dp[x1][y1]+1;
            fa[x2][y2]=true;
            q1.push({x2,y2});
        }
    }
    return -1;
}

int main()
{
    
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            dp[i][j]=1e6;
            fa[i][j]=false;
            // cout<<arr[i][j]<<' ';
        }
        // cout<<"\n";
    }
    int x=0;int y=0;
    cin>>x>>y>>en_x>>en_y;
    x--;y--;en_x--;en_y--;
    
    int ans = bfs(x,y);
    cout<<ans<<"\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            // cout<<dp[i][j]<<' ';
        }
        // cout<<"\n";
    }
    return 0;
}