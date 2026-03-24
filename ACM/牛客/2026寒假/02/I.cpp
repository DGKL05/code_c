#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int m=0;
    cin>>n>>m;
    vector<string>arr(n);
    map<char,int>m1;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        for(auto x:arr[i]) m1[x]++;
    }
    vector<vector<char>>ans(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(m1[arr[i][j]] != 1) ans[i][j] = 'Y';
            else ans[i][j] = 'N';
        }
    }
    for(auto x : ans){
        for(auto k : x) cout<<k;
        cout<<"\n";
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}