#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int m=0;int q=0;
    cin>>n>>m>>q;
    vector<vector<bool>>arr(n+1,vector<bool>(m+1));
    while(q--){
        int op = -1;
        cin>>op;
        int idx =0;
        cin>>idx;
        if(op == 1){
            for(int i=1;i<=n;i++){
                arr[i][idx] = true;
            }
        }else {
            for(int i=1;i<=m;i++){
                arr[idx][i] = true;
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(arr[i][j] == false) ans++;
        }
    }
    cout<<ans<<"\n";
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