#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void print(vector<vector<int>>&arr){
    for(auto x:arr){
        for(int i=0;i<x.size();i++){
            int y = x[i];

            if(y) cout << y <<" ";

        }
        cout<<"\n";
    }
}

void test(){
    int n=0;
    cin>>n;
    vector<vector<int>>arr(n,vector<int>(n));
    arr[0][0] = 1;
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            if(j == 0) {
                arr[i][j] = 1;
                continue;
            }
            arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
        }
    }
    print(arr);
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