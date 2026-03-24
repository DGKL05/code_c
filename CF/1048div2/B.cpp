#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int m=0;
    cin>>n>>m;
    vector<ll>arr(n);
    for(auto &x:arr){
        cin>>x;
    }
    sort(arr.begin(),arr.end());
    ll ans=0;
    for(int i=n-1;i>=0;i--){
        if(m==0) break;
        ans+=1LL*arr[i]*m;
        m--;
    }
    cout<<ans<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}