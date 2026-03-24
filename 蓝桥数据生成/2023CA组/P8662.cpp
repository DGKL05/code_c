#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
int n;
bool fa[N][N];
char arr[N][N];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool bfs(int x,int y)
{
    bool kt = true;
    queue<pair<int,int>>q1;
    q1.push({x,y});
    fa[x][y]=true;
    while(q1.size()){
        bool t1=false;
        pair<int,int>p1 = q1.front();
        q1.pop();
        int x1 = p1.first;int y1 = p1.second;
        fa[x1][y1]=true;
        //cout<<"x = "<<x1<<" y = "<<y<<"\n";
        for(int i=0;i<4;i++){
            int x2=x1+dx[i];int y2=y1+dy[i];
            //cout<<"x = "<<x2<<" y = "<<y2<<"\n";
            //cout<<"n = "<<n<<'\n';
            if(x2>=n||x2<0||y2>=n||y2<0) continue;
            if(fa[x2][y2]) continue;
            if(arr[x2][y2]=='.') t1 = true;
            if(arr[x2][y2]=='#') {
                q1.push({x2,y2});
                fa[x2][y2]=true;
                //cout<<"x = "<<x2<<" y = "<<y2<<"\n";
            }
        }
        if(!t1) kt = false;
    }
    return kt;
}

int main()
{
    //int n=0;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            fa[i][j]=false;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]=='#'&&!fa[i][j]){
                //cout<<arr[i][j]<<"\n";
                if(bfs(i,j)) ans++;
                fa[i][j]=true;
                
            }
        }
    }
    cout<<ans<<"\n";
}