#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int q=0;
    cin>>n>>q;
    vector<ll>a(n),b(n),minarr(n);
    ll sum_a=0;ll sum_b=0;ll ans=0;
    for(auto &x:a) cin>>x,sum_a+=x;
    for(auto &x:b) cin>>x,sum_b+=x;
    for(int i=0;i<n;i++){
        minarr[i]=min(a[i],b[i]);
        ans+=minarr[i];
    }
    for(int t=0;t<q;t++){
        char op;ll x=0;ll v=0;
        cin>>op>>x>>v;
        x--;
        ll temp=0;
        // cout<<sum_a<<" "<<sum_b<<"\n";
        if(op=='A') {
            if(a[x]<b[x]){
                temp=v-a[x];
                ll num=b[x]-a[x];
                a[x]=v;
                if(a[x]<=b[x]){
                    ans+=temp;
                }else {
                    ans+=num;
                }
            }else {
                temp=v-a[x];
                ll num=a[x]-b[x];
                a[x]=v;
                 if(a[x]<=b[x]){
                    ans+=(v-b[x]);
                }
            }
        }else {
           if(a[x]>b[x]){
                temp=v-b[x];
                ll num=a[x]-b[x];
                b[x]=v;
                if(b[x]<=a[x]){
                    ans+=temp;
                }else {
                    ans+=num;
                }
            }else {
                b[x]=v;
                 if(a[x]>b[x]){
                    ans+=(v-a[x]);
                }
            }
        }
        cout<<ans<<"\n";
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}