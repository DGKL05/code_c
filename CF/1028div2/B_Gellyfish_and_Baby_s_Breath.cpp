#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const int p = 998244353;
ll power(ll k)  // 求a^k mod p
{
    ll a=2;
    ll res = 1 % p;
    while (k)
    {
        if (k & 1) res = (ll)res * a % p;
        a = (ll)a * a % p;
        k >>= 1;
    }
    return res;
}

struct node{
    ll a;int idx;
};

void test()
{
    int n=0;
    cin>>n;
    vector<node>a1(n),a2(n);
    vector<ll>v1(n),v2(n);
    for(int i=0;i<n;i++){
        ll num=0;
        cin>>num;
        v1[i]=num;
        if(i==0){
            a1[i].a=num;
            a1[i].idx=i;
        }else if((ll)a1[i-1].a<=num) {
            a1[i].a=num;
            a1[i].idx=i;
        }else {
            a1[i].a=a1[i-1].a;
            a1[i].idx=a1[i-1].idx;
        }
    }
    for(int i=0;i<n;i++){
        ll num=0;
        cin>>num;
        v2[i]=num;
        if(i==0){
            a2[i].a=num;
            a2[i].idx=i;
        }else if((ll)a2[i-1].a<=num) {
            a2[i].a=num;
            a2[i].idx=i;
        }else {
            a2[i].a=a2[i-1].a;
            a2[i].idx=a2[i-1].idx;
        }
    }
    ll t2=a2[0].a;
    ll t1=a1[0].a;
    cout<<(power(t1)%p+power((ll)t2)%p)%p<<' ';
    for(int i=1;i<n;i++){
        ll ans=0;int id=0;
        ll t2=v2[i-a1[i].idx];
        ll t1=a1[i].a;
        // cout<<i<<' '<<i-a1[i].idx<<" : ";
        ans=(power(t1)%p+power((ll)t2)%p)%p;
        t2=v1[i-a2[i].idx];
        t1=a2[i].a;
        // cout<<"t1 = "<<t1<<" t2 = "<<t2<<"\n";
        cout<<max((ll)(power(t1)%p+power((ll)t2)%p)%p,(ll)ans%p)<<" ";
    }
    cout<<"\n";
}

int main()
{
    // cout<<2*power(6)<<' '<<power(10)<<"\n";
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}