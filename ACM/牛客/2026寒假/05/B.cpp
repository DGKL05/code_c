#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int m=0;
    cin>>n>>m;
    vector<vector<char>>ans(n,vector<char>(m));
    for(int i=0;i<m;i++){
        if(i&1) ans[0][i] = '\\';
        else ans[0][i] = '\/';
    }
    // for(int i=0;i<m;i++) cout<<ans[0][i];
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(ans[i-1][j] == '\\') ans[i][j] = '\/';
            else ans[i][j] = '\\';
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ans[i][j];
        }
        cout<<"\n";
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}