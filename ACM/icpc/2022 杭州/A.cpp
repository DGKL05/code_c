#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    ll n = 0;ll m = 0;
    cin>>n>>m;
    vector<ll>arr(n);
    ll sum=0;
    for(auto x:arr){
        cin>>x;
        sum+=x;
    }
    ll g = __gcd(n,m);
    int d=-1;
    ll ans = min(sum % m % g,(sum+1LL*n%m*(n+1)%m/2) % m % g);
    if(ans == sum % m % g){
        d=0;
    }else d=1;
    // cout<<ans<<"\n";
    int s = -1;
    ll temp = (ans- (sum + d*1LL*n*(n+1)/2))% m;
    if(temp<0){
        temp += m;
    }
    for(ll k = -n;k<=n;k++){
        if((temp - 1LL*k*m)%n == 0){
            s = (temp - 1LL*k*m)/n;
            if(s>=0 && s<m){
                cout<<ans<<"\n"<<s<<" "<<d<<"\n";
                return ;
            }
        }
    }
    if(s==-1){
        s=0;
        cout<<ans<<"\n"<<s<<" "<<d<<"\n";
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