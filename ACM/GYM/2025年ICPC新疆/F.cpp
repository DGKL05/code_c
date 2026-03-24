#include<bits/stdc++.h>
using namespace std;
using ll =long long;


void test()
{
    int n,k;
    cin>>n>>k;
    vector<vector<pair<int,int> > > pos(k+1);
    int dp[51][51]={0};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int t;
            cin>>t;
            pos[t].push_back({i,j});
        }
    }
    if(pos[1].size()==0){
        cout<<-1;
        return ;
    }
    int te=pos[2].size();
    for(int i=2;i<=k;i++){
        int size=pos[i].size();
        if(size==0){
            cout<<-1;
            return ;
        }
        int size1=pos[i-1].size();
        for(int j=0;j<size;j++){
            int xt=pos[i][j].first;
            int yt=pos[i][j].second;
            for(int z=0;z<size1;z++){
                int xt1=pos[i-1][z].first;
                int yt1=pos[i-1][z].second;
                int dis=abs(xt-xt1)+abs(yt-yt1);
                if(z==0){
                    dp[xt][yt]=dp[xt1][yt1]+dis;
                }else{
                    dp[xt][yt]=min(dp[xt][yt],dp[xt1][yt1]+dis);
                }
            }
        }
    }
     
//  for(int i=1;i<=n;i++){
//      for(int j=1;j<=n;j++){
//          cout<<dp[i][j]<<" ";
//      }
//  }
    int lastsize=pos[k].size();
    int minvalue=100000;
    for(int i=0;i<lastsize;i++){
        int xk=pos[k][i].first;
        int yk=pos[k][i].second;
        minvalue=min(dp[xk][yk],minvalue);
    }
    cout<<minvalue;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}
