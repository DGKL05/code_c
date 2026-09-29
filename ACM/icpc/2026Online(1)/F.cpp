#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void test(){
    int n = 0;
    int m = 0;
    cin>>n>>m;
    vector<ll>arr(n+1,0);
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            ll ans = 0;
            cin>>ans;
            arr[i]+=ans;
        }
    }
    ll ans =0;
    for(int i=1;i<=n;i++){
        if(arr[i-1] > arr[i]) ans++;
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin>>T;
    while(T --) test();
    return 0;
}