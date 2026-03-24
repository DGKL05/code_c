#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    vector<vector<int>>arr(n);
    vector<int>du(n,0);
    for(int i=1;i<n;i++){
        int a=0;int b=0;
        cin>>a>>b;
        --a;--b;
        du[a]++;
        du[b]++;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    ll ans = 0;
    int ans_idx=0;
    for(int i=0;i<n;i++){
        ll temp = 0;
        for(auto x:arr[i]){
            temp += (du[x]-1);
        }
        if(temp > ans){
            ans = temp;
            ans_idx = i;
        }
    }
    cout<<ans_idx + 1 << " " << ans <<"\n";
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