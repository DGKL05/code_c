#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void test(){
    int n=0;
    cin>>n;
    vector<vector<int>>arr(n+1,vector<int>(n+1));
    int x=1;int y=(n+1)/2;
    arr[x][y] = 1;
    for(int i=2;i<=n*n;i++){
        // cout<<x<< " " <<y<<"\n";
        if(x == 1){
            if(y != n) {
                x = n;
                y = y + 1;
            }else {
                x += 1;
            }
        }else if(y == n){
            if(x != 1){
                x -= 1;
                y = 1;
            }
        }else {
            if(arr[x-1][y+1] == 0){
                x -= 1;
                y += 1;
            }else {
                // x -= 1;
                x += 1;
            }
        }
        arr[x][y] = i;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin>>T;
    while(T--) test();
    return 0;
}