#include<bits/stdc++.h>

using namespace std;
using ll = long long;


void test(){
    string s1;
    int n=0;
    cin>>s1>>n;
    if(s1 == "first"){
        vector<vector<int>>arr(n,vector<int>(n));
        for(int i=0;i<n;i++) cin>>arr[0][i];
        arr[1][n-1] = arr[0][n-1];
        for(int i=0;i<n-1;i++){
            if(i == 0) arr[1][0] = arr[0][n-2];
            else arr[1][i] = arr[0][i-1];
        }
        for(int i=2;i<n;i++){
            for(int j=0;j<n;j++){
                if(j == 0) arr[i][j] = arr[i-1][n-1];
                else arr[i][j] = arr[i-1][j-1];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<"\n";
        }
    }else {
        vector<vector<int>>arr(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>arr[i][j];
            }
        }
        map<int,int>m1;
        for(int i=0;i<n;i++){
            m1[arr[i][n-1]]++;
        }
        int ans = 0;
        for(auto [l,r]:m1){
            if(r == 2){
                ans = l;
            }
        }
        map<int,int>m2;
        map<int,int>m3;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j] == ans){
                    int num=0;
                    if(j == 0) num = arr[i][n-1];
                    else num = arr[i][j-1];
                    m2[num]++;
                    m3[num] = i;
                }
            }
        }
        for(auto [l,r] : m2){
            if(r == 1) ans = l;
        }
        auto it = m3.find(ans);
        int idx = it->second;
        for(int i=0;i<n;i++){
            cout<<arr[idx][i]<<" ";
        }
        cout<<"\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin>>T;
    while(T--) test();
    return 0;
}