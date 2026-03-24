#include<bits/stdc++.h>
using namespace std;
using ll =long long;


const int N=110;
int n,k,x,y;
int a[N][N];
bool st[N][N];
int dx[8]={1,2,1,2,-1,-2,-1,-2},dy[8]={2,1,-2,-1,2,1,-2,-1};
int ans;
 
void dfs(int x,int y,int num){
    st[x][y]=true;
    ans++;
    if(num==k)return;
    for(int i=0;i<8;i++){
        int a=x+dx[i],b=y+dy[i];
        if(a<1||a>n||b<1||b>n)continue;
        if(!st[a][b]){
            dfs(a,b,num+1);
        }
    }
}

void test()
{
    cin>>n>>k>>x>>y;
    dfs(x,y,0);
    cout<<ans<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}