#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void test()
{
    int n=0;
    cin>>n;
    set<ll>s1;
    for(int i=0;i<n;i++){
        ll num=0;
        cin>>num;
        s1.insert(num);
    }
    int q=0;
    cin>>q;
    ll ans=0;
    while(q--){
        ll k=0;
        cin>>k;
        
    }
    cout<<ans<<"\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T = 1;
    cin>>T;
    while(T--) test();

    return 0;
}