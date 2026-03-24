#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int q=0;ll s=0;
    cin>>n>>q>>s;
    vector<ll>arr(n+1,0),v1(n+1,0);
    for(int i=1;i<=n;i++) cin>>v1[i];
    for(int i=1;i<=n;i++){
        arr[i] = v1[i] + arr[i-1]  ;
    }
    // for(auto x:arr) cout<<x<<" ";
    // cout<<"\n";
    while(q--){
        int x=0;ll y=0;
        cin>>x>>y;
        y--;
        x--;
        cout<< s + arr[x] + y<<"\n";
    }
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