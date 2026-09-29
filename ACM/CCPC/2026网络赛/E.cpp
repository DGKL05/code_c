#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void test(){
    int n;
    cin>>n;

    vector<vector<int>>a(3,vector<int>(n));

    for(int i=0;i<3;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }

    vector<int>ok(n+1,0);

    for(int x=0;x<3;x++){
        for(int y=x+1;y<3;y++){

            vector<int>pos(n+1);

            for(int i=0;i<n;i++){
                pos[a[y][i]] = i+1;
            }

            int mx = 0;

            for(int i=0;i<n-1;i++){
                mx = max(mx,pos[a[x][i]]);

                if(mx == i+1){
                    ok[i+1] = 1;
                }
            }
        }
    }

    int ans = 1;

    for(int i=1;i<n;i++){
        if(ok[i]) ans++;
    }

    cout<<ans<<"\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T = 1;
    cin>>T;

    while(T--) test();

    return 0;
}