#include<bits/stdc++.h>
using ll = long long;

using namespace std;

void test(){
    vector<ll> arr(3,0);
    ll ma = 0;
    ll mi = 1e12;
    ll ans = 0;
    for(int i=0;i<3;i++){
        cin>>arr[i];
        mi = min(mi , arr[i]);
        ma = max(ma , arr[i]);
        ans+=arr[i];
    }
    ll tow = ans-ma-mi;
    if(ma <= tow+mi){
        cout<<ma - mi<<"\n";
    }else cout<<tow<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin>>T;
    while(T--) test();
    return 0;
}