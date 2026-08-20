#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void test(){
    int n=0;
    cin>>n;
    vector<int>arr(n+1);
    int m=0;
    cin>>m;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ll ans = 1e18;
    ll tmp =0;
    for(int i=0;i<m;i++){
        tmp += arr[i];
    }
    ans = min(ans,tmp);
    for(int i=1;i<n-m;i++){
        tmp -= arr[i-1];
        tmp += arr[i+m-1];
        ans = min(tmp,ans);
    }
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin>>T;
    while(T--) test();
    return 0;
}