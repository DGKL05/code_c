// 4 3 3 2 2 1 1
// 5 4 4 3 3 2 2 1 1
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int n=0;

int check(vector<vector<int>>&arr,int x,int y){
    for(int i=0;i<4;i++){
        int x1 = x + dx[i];
        int y1 = y + dy[i];
        if(x1 >= n || y1 >= n || x1 < 0 || y1 < 0) continue;
        if(arr[x1][y1] == 0) return i;
    }
    return 1;
}

void print(vector<vector<int>>&arr){
    for(auto x:arr){
        for(int i=0;i<x.size();i++){
            int y = x[i];
            cout << setw(3) << y;

        }
        cout<<"\n";
    }
}

void test(){

    cin>>n;
    int idx = 0;
    vector<vector<int>>arr(n,vector<int>(n));
    vector<int>bu;
    for(int i=1;i<n;i++){
        bu.push_back(n-i);
        bu.push_back(n-i);
    }
    for(int i=0;i<n;i++) arr[0][i] = i+1;
    int num = n;
    int k=1;
    int x=0;
    int y=n-1;
    int ans = n + 1;
    int b=0;
    while(b<(n-1)*2){
        int fa = check(arr,x,y);
        // cout<<"fangxaing : "<<fa<<" ";
        // cout<<bu[idx]<<"\n";
        for(int i=0;i<bu[idx];i++){
            int x1 = x + dx[fa];
            int y1 = y + dy[fa];
            arr[x1][y1] = ans++;
            // cout<<x1<<" "<<y1<<"\n";
            x = x1;
            y = y1;
        }
        b++;
        idx++;
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