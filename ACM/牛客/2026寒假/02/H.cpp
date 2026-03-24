#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    vector<ll>arr(n+1,0);
    for(int i=1;i<=n;i++) cin>>arr[i];
    map<ll,int>m1;
    ll ans=0;ll sum=0;ll temp =0;
    for(int i=1;i<=n;i++){
        if(m1.find(arr[i]) != m1.end()){
            temp = m1[arr[i]];
        }else temp = 0;
        sum += (i - temp);
        ans += 1LL*(sum) * (n - i + 1);
        m1[arr[i]] = i;
    }
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