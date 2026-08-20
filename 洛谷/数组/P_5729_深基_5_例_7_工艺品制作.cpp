#include<bits/stdc++.h>

using namespace std;
using ll  =long long;

void test(){
    int X=0;int Y=0;int Z=0;
    cin>>X>>Y>>Z;
    vector<vector<vector<int>>>arr(X+1,vector<vector<int>>(Y+1,vector<int>(Z+1)));
    int q=0;
    cin>>q;
    while(q--){
        int a=0;int b=0;int c=0;int a1=0;int b1=0;int c1=0;
        cin>>a>>b>>c>>a1>>b1>>c1;
        for(int i=a;i<=a1;i++){
            for(int j=b;j<=b1;j++){
                for(int k=c;k<=c1;k++){
                    arr[i][j][k]=1;
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<=X;i++){
        for(int j=1;j<=Y;j++){
            for(int K=1;K<=Z;K++){
                if(arr[i][j][K] != 1) ans++;
            }
        }
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin>>T;
    while(T--) test();
    return 0;
}