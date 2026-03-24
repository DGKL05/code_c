#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    ll n=0;ll m=0;ll k=0;ll ans=0;
    cin>>n>>m>>k;
    ll a=0;
    a=m/2;
    ans=(k/n);
    if(k%n!=0) ans++;
    if(m%2==1) a++;
    // if(n*a>=k){
    //     cout<<"1\n";
    //     return ;
    // }
//     k-=n*a;
//     //cout<<"k="<<k<<"\n";
//     ans+=(k/n);//cout<<ans<<"\n";
//     if(k%n!=0) ans++;
//     ans+=a;
//     cout<<ans<<" "<<a<<"\n";
   if(ans<=a){
        cout<<"1\n";
        return ;
   }
   if(ans==m){
        cout<<ans<<"\n";
        return ;
   }
    ll num=1;    
        if(m-1==ans) {
            cout<<m/2<<"\n";
            return ;
        }
        for(ll i=a+1;i<=ans;i+=2){
            num++;
        }
   cout<<num<<"\n";
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);std::cout.tie(0);
    int t=0;
    cin>>t;
    while(t--) test();
    return 0;
}