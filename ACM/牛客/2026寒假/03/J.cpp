#include<bits/stdc++.h>
using namespace std;
using ll =long long;

int chen(ll num){
    int ans = 0;
    while(num){
        ans++;
        num>>=1;
    }
    return ans;
}

bool chenk(ll num){
    int ans = 0;
    while(num){
        if(num&1) ans++;
        if(ans > 1) return false;
        num>>=1;
    }
    return true;
}

ll power(ll num){
    ll ans = 1;
    ll a=2;
    while(num){
        if(num&1) ans *=a;
        a*=a;
        num>>=1;
    }
    return ans;
}

void test()
{
    ll n=0;int q=0;
    cin>>n>>q;
    ll ans = 0;
    int chenshu=chen(n);
    if(!chenk(n)){
        int k = chen(n);
        k --;
        for(int i=0;i<k;i++){
            ans +=power(i);
        }
        // ans = n - ans;
        // cout<<k<<" "<<ans<<"\n";
    }
    while(q--){
        ll num = 0;
        cin>>num;
        int k = chen(num);
        if(k == chenshu){
            cout<<(n - ans)<<"\n";
            continue;
        }
        cout<<power(k-1)<<"\n";
    }
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