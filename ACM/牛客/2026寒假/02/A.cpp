#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    // cout<<"Hello world\n";
    vector<ll>arr(3);
    ll ans=0;
    int idx = -1;
    for(int i=0;i<3;i++) {
        cin>>arr[i];
        ans += arr[i];
    }
    int cnt=0;
    for(int i=0;i<3;i++){
        if(arr[i] > 1LL*(ans/3)+1){
            cout<<"NO\n";
            return ;
        }
        if(arr[i] == 1LL*(ans/3) + 1) cnt++;
    }
    if(cnt != 1LL*((ans)%3)) cout<<"NO\n";
    else cout<<"YES\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}