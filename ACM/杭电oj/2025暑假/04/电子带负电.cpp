#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const int MOD = 998244353;
const int inv2 = 499122177;
void test()
{
    int n=0;
    cin>>n;
    vector<ll>v1(n);
    ll l=1;ll r=1;bool fa=true;ll ans=0;ll min_n=1e18;ll max_n=-1e18;ll num=0;
    for(int i=0;i<n;i++){
        cin>>v1[i];
        if(v1[i]==0&&fa){
            l++;
        }else fa=false;
        num+=v1[i];
        max_n=max(v1[i],max_n);
        if(v1[i]!=0) min_n=min(min_n,v1[i]);
    }
    fa=true;
    for(int i=n-1;i>=0;i--){
        if(fa&&v1[i]==0){
            r++;
        }else fa=false;
    }
    if(l==r && l==n+1){
        cout<<"0 ";
        ans=(1LL*n*(n+1)%MOD*inv2)%MOD;
        ans=(1LL*ans%MOD*(n+1)%MOD*(n+1)%MOD)%MOD;
        cout<<ans<<"\n";
        return ;
    }
    // if(min_n==-1) min_n=1;
    cout<<num<<" ";
    ans=(min_n+n+1)%MOD*((n-max_n+MOD)%MOD+1)%MOD;
    // cout<<":  "<<(min_n+n+1)<<" "<<(n-max_n+1)<<"\n";
    ans=(ans%MOD*(l%MOD*r%MOD)%MOD)%MOD;
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