#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n = 1e2;
    
    // for(int i=3;i<=n;i++){
    //     cout<<i<<"\n";
    // }
    for(int i=3;i<=n;i++){
        int ans = 0;
        for(int a = 1;a<i/2;a++){
            ans = max(ans,__gcd(a,i-a));
        }
        cout<<ans<<"\n";
    }
    // cout<<ans<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}