#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n=0;int m=0;int k=0;
int print(vector<vector<int>>&arr){
    int ans=0;
    for(auto x:arr){
        for(int i=0;i<x.size();i++){
            int y = x[i];
            if(y == 0) ans++;;
            // cout<<y<<" ";
        }
        // cout<<"\n";
    }
    return ans;
}
int dx[12] = {0,1,0,-1,1,1,-1,-1,0,2,0,-2};
int dy[12] = {1,0,-1,0,1,-1,-1,1,2,0,-2,0};

void move(vector<vector<int>> &arr,int x,int y){
    arr[x][y] = 1;
    for(int i=0;i<12;i++){
        int x1 = x + dx[i];
        int y1 = y + dy[i];
        // cout<<x1+1<<" "<<y1+1<<"\n";
        if(x1 >= n || y1 >= n || x1 < 0 || y1 < 0) continue;
        arr[x1][y1] = 1;
    }
}

void test(){

    cin>>n>>m>>k;
    vector<vector<int>>arr(n,vector<int>(n));
    for(int i=0;i<m;i++){
        int x=0;int y=0;
        cin>>x>>y;
        x--;y--;
        move(arr,x,y);
    }
    for(int i=0;i<k;i++){
        int x=0;int y=0;
        cin>>x>>y;
        x--;y--;
        arr[x][y] = 1;
        for(int i = x-2;i <= x + 2 ;i++){
            for(int j = y-2 ; j <= y + 2;j++){
                int x1 = i;int y1 = j;
                if(x1 >= n || y1 >= n || x1 < 0 || y1 < 0) continue;
                arr[x1][y1] = 1;
            }
        }
    }
    cout<< print(arr) <<"\n";
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