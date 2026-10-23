
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void test(){
    ll n,k,t;
    cin>>n>>k>>t;

    vector<ll>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    ll ans=0;
    ll nex=0;
    for(int i=0;i<n;i++){
        if(arr[i]>t) break;
        if(arr[i]>nex){
            ans+=(arr[i]-nex+k-1)/k;
        }
        nex=arr[i]+k;
    }
    if(nex<t){
        ans+=(t-nex+k-1)/k;
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T=1;
    while(T--) test();
    return 0;
}
