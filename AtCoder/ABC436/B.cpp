#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void test()
{
    int n=0;
    cin>>n;
    vector<vector<int>>arr(n,vector<int>(n));
    int r = 0;
    int c = (n-1)/2;
    int k=0;
    for(int i=0;i<n*n;i++){
        arr[r][c] = ++k;
        if(arr[(r+n-1)%n][(c+1)%n] == 0) {
            r = (r + n -1)%n;
            c = (c+1)%n;
        }else {
            r = (r+1)%n;
            c = c;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T=1;
    // cin>>T;
    while(T--) test();
    return 0;
}