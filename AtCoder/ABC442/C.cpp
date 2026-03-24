#include<bits/stdc++.h>
using namespace std;
using ll =long long;
using ull = unsigned long long;

void test()
{
    int n = 0;
    int m=0;
    cin>>n>>m;
    // vector<int>arr(n+1 , 0);
    vector<ull>ans(n+1 , n-1);
    for(int i=0;i<m;i++){
        int a=0;int b=0;
        cin>>a>>b;
        ans[a]--;
        ans[b]--;
    }
    // for(auto x:arr){
    //     cout<<x<<" ";
    // }
    // cout<<"\n";
    for(int i=1;i<=n;i++){
        cout<<1LL*ans[i]*((ans[i] - 1) * (ans[i] - 2) )/6<<" ";
    }
    cout<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}
