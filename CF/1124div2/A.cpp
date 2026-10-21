#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll pow1(ll n,ll a){
    ll ans=1;
    for(int i=0;i<n;i++){
        ans*=2;
    }
    return ans;
}

void test()
{
    ll n=0;ll k=0;
    cin>>n>>k;
    cout<<(k-1)*2 + pow1(n-k+1,2)<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin>>T;
    while(T--) test();
    return 0;
}