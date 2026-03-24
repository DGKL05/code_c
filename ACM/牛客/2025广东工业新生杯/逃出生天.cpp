#include<bits/stdc++.h>
using namespace std;
using ll =long long;

int n;int m;int k;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int arr[1005][1005];
bool dis[1005][1005];
bool fa=false; 

struct node{
    int x;int y;
};

void bfs(){
    queue<node>q1;
    q1.push({0,m-1});
    dis[0][m-1]=true;
    while(q1.size()){
        auto [l,r] = q1.front();
        q1.pop();
        // if(dis[l][r]) continue;
        dis[l][r]=true;
        if(l==(n+1) && r==0){
            fa=true;
            return ;
        }
        for(int i=0;i<4;i++){
            int tx=l+dx[i];
            int ty=r+dy[i];
            // cout<<tx<<" "<<ty<<"\n";
            if(tx<0 || tx>=n+2 || ty<0 || ty>=m) continue;
            if(dis[tx][ty]) continue;
            if(arr[tx][ty]) continue;
            dis[tx][ty]=true;
            q1.push({tx,ty});
        }
    }
}

void test()
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int p=0;char a;
        cin>>p>>a;
        if(a=='L'){
            for(int j=p-1;j>=0;j--){
                arr[i+1][j]=1;
            }
        }else {
            for(int j=p-1;j<m;j++){
                arr[i+1][j]=1;
            }
        }
    }
    // for(int i=0;i<=n+1;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    bfs();
    if(fa) cout<<"YES\n";
    else cout<<"NO\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}