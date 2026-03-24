#include<bits/stdc++.h>
using namespace std;
using ll =long long;

const ll mod = 1000000007;
const ll inv2 = 500000004;

struct node {
    ll val;
    ll a;
    bool operator<(const node &a){
        return a.val>val;
    }
};

ll f(vector<node> &arr) {
    sort(arr.begin(),arr.end());
    ll sum_a=0;ll sum_val=0;ll sum_aval=0;ll ans=0;int n=arr.size();
    for (int j = 0; j < n; j++) {
        ll a=arr[j].a;
        ll val=arr[j].val;
        a=(a%mod+mod)%mod;
        val=(val%mod+mod)%mod;
        if(j>0){
            ll num=(val*sum_a%mod+(mod-sum_aval)%mod)%mod;
            num=(num+a*val%mod*j%mod)%mod;
            num=(num+(mod-a*sum_val%mod)%mod)%mod;
            ans=(ans+num)%mod;
        }
        sum_a=(sum_a+a)%mod;
        sum_val=(sum_val+val)%mod;
        sum_aval=(sum_aval+a*val%mod)%mod;
    }
    return ans%mod;
}

void test()
{
    int n=0;
    cin>>n;
    vector<node>u,v;
    for (int i=0; i<n;i++) {
        ll x,y,a;
        cin>>x>>y>>a;
        u.push_back({x+y,a});
        v.push_back({x-y,a});
    }

    ll num1=f(u);
    ll num2=f(v);
    ll ans =(num1+num2)%mod*inv2%mod;
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