#include<bits/stdc++.h>
using namespace std;
using ll =long long;

struct node{
    ll s;ll d;
};

bool cmp(node &a,node &b){
    if(a.s == b.s) return a.d > b.d;
    return a.s < b.s; 
}

void test()
{
    int n=0;
    cin>>n;
    vector<node>arr(n);
    for(int i = 0;i<n;i++){
        cin>>arr[i].s>>arr[i].d;
    }
    sort(arr.begin() , arr.end(),cmp);
    // for(auto x:arr){
    //     cout<<x.s<<" "<<x.d<<"\n";
    // }
    int temp=0;ll ans=0;
    for(auto x:arr){
        ans = max(ans , x.s) + x.d;
    }
    // cout<<ans<<" "<<temp<<"\n";
    cout<<ans<<"\n";
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