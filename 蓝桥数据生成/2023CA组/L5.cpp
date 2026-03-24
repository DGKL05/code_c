#include <bits/stdc++.h>
using namespace std;
const int N = 5050;
bool arr[N][N]={false};
vector<pair<int,int>>v1(4);

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

void bfs(int x,int y)
{
    queue<pair<int,int>>q1;
    q1.push({x,y});
    arr[x][y]=true;
    //int num=0;
    while(q1.size()){
        pair<int,int>p1=q1.front();
        q1.pop();
        int x1=p1.first;int y1=p1.second;
        if(x1>x+2020||y1>y+2020||x1<x-2020||y1<y-2020) continue;
        arr[x1][y1]=true;
        for(int i=0;i<4;i++){
            int x2=x1+dx[i];int y2=y1+dy[i];
            if(x2<0||x2>5051||y2<0||y2>5051) continue;
            if(arr[x2][y2]) continue;
            q1.push({x2,y2});
        }
        //num++;
    }
}

int main(){

	v1[0]={0,0};v1[1]={2020,11};v1[2]={11,14};v1[3]={2000,2000};
    for(int i=0;i<4;i++){
        int x=v1[i].first;
        int y=v1[i].second;
        bfs(x,y);
    }
    int ans=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(arr[i][j]) ans++;
            cout<<arr[i][j]<<' ';
        }
        cout<<"\n";
    }
    cout<<ans<<"\n";
	return 0;
}