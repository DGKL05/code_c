#include<bits/stdc++.h>
using namespace std;
using ll =long long;

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

void test()
{
    int n=0;int m=0;
    cin>>n>>m;
    vector<string>arr(n);
    for(int i=0;i<n;i++){
        string s1;
        cin>>s1;
        arr[i]=s1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='#'){
                int ans=0;
                for(int k=0;k<4;k++){
                    int x=i+dx[k];int y=j+dy[k];
                    if(x<0 || y<0 || x>=n || y>=m) continue;
                    if(arr[x][y]=='#') ans++;
                }
                if(ans!=2 && ans!=4) {
                    // cout<<i<<" "<<j<<" ans = "<<ans<<"\n";
                    cout<<"No\n";
                    return ;
                }
            }
        }
    }
    cout<<"Yes\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}