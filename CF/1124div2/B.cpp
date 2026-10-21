#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll f(ll a){
    ll ans=0;
    while(a){
        ans+=(a%10)*(a%10);
        a/=10;
    }
    return ans;
}

void test(){
    int n=0;
    cin>>n;
    map<ll,ll>m1;
    for(int i=0;i<n;i++){
        ll num=0;
        cin>>num;
        for(int j=0;j<1000;j++){
            num=f(num);
        }
        m1[num]++;
    }
    ll ans=0;
    for(auto [l,r]:m1){
        ans+=r*(r-1)/2;
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T=1;
    cin>>T;
    while(T--) test();
    return 0;
}