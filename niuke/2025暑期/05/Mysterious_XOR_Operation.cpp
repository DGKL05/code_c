#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void test(){
    int n=0;
    cin>>n;
    vector<ll>v1(n);
    for(int i=0;i<n;i++){
        cin>>v1[i];
    }
    ll ans=0;
    for(int k=0;k<=31;k++){
        ll num=(1LL<<(k+1))-1;
        ll cnt[4]={0,0,0,0};
        for(int i=0;i<n;i++){
            ll x=v1[i]&num;
            int j=(x>>k);
            int num2=__builtin_popcount(x);
            if(j%2==0){
                if(num2%2==1) cnt[0]++;
                else cnt[1]++;
            }else{
                if(num2%2==1) cnt[2]++;
                else cnt[3]++;
            }
        }
        ans+=1LL*(cnt[0]*cnt[3]+cnt[1]*cnt[2])*(1LL<<k);
    }
    cout<<ans<<"\n";
}

int main(){
    std::ios_base::sync_with_stdio(false);
    int T=1;
    //cin>>T;
    while(T--)test();
    return 0;
}