#include<bits/stdc++.h>
using namespace std;
using ll =long long;

ll power(ll a, ll k)  // 求a^k mod p
{
    ll res = 1;
    while (k)
    {
        if (k & 1) res = (ll)res * a;
        a = (ll)a * a ;
        k >>= 1;
    }
    return res;
}


void test()
{
    int n=0;ll c=0;
    cin>>n>>c;
    vector<ll>v1;
    ll ans=0;
    for(int i=0;i<n;i++){
        ll num=0;
        cin>>num;
        if(num > c){
            ans++;
        }else{
            v1.push_back(num);
        }
    }
    sort(v1.begin(),v1.end());
    int n1=v1.size();
    ll time=0;
    for(int i=n1-1;i>=0;i--){
        // cout<<": "<<1LL*v1[i]*2*time<<"\n";
        if(1LL*v1[i]*((ll)power(2,time))>(ll)c) ans++;
        else time++;
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