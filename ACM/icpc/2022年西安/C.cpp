#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll>arr;
ll MAX_num = 1e9;

void init()
{
    ll num = 0;
    arr.push_back(1);
    int i=1;
    for(i=1;num<=MAX_num;i++){
        arr.push_back(1LL*arr[i-1]*2);
        num = 1LL*arr[i-1]*2;
    }
    // cout<<i<<"\n";
    // cout<<"hei : "<<((MAX_num < arr[i-1]) ? 1 : 0)<<"\n";
    // cout<<MAX_num<<" "<<arr[i-1]<<"\n";
    arr.push_back(arr[i-1]*2);
}

void test()
{
    ll a=0;ll b=0;ll c=0;
    cin>>a>>b>>c;
    int idx=0;
    ll ans=1e18;
    for(int i=1;i<=31;i++){
        // cout<<"ans = "<<1LL*i*a+1LL*(c+arr[i]-1)/arr[i]*b<<"\n";
        ll num = c/arr[i];
        if(c%arr[i] != 0) num++;
        ans = min(ans,1LL*i*a+1LL*num*b);
        if(arr[i] >= c) break;
    }
    ans = min(ans,1LL*b*c);
    cout<<ans<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    init();
    // for(int i=0;i<10;i++) cout<<arr[i]<<" ";
    while(T--) test();
    return 0;
}