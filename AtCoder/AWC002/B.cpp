#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int m=0;ll k = 0;
    cin>>n>>m>>k;
    vector<ll>arr(n);
    for(auto &x:arr){
        cin>>x;
    }
    ll ans = 0;int ans_num=0;
    for(int i=0;i<m;i++){
        ll num=0;
        cin>>num;
        if(arr[num-1] < k){
            ans+=arr[num-1];
            ans_num++;
        }
    }
    cout<<ans_num<<" "<<ans<<"\n";
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