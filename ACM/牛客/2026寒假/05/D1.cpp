#include<bits/stdc++.h>
using namespace std;
using ll =long long;

const ll MOD = 1e9+7;

ll f(ll c,ll w){
    ll ans=0;
    // cout<<c<<" "<<w<<" ";
    while(c >= 2){
        ans+=1LL*(1LL*c*w)%MOD;
        c>>=1;
    }
    // cout<<ans<<"\n";
    return ans;
}

void test()
{
    int n=0;
    cin>>n;
    multiset<ll>s1;
    ll ans=0;
    for(int i=0;i<n;i++){
        ll c=0;ll w=0;
        cin>>c>>w;
        if(c == 1) {
            s1.insert(w%MOD);
        }else {
            if(c&1) {
                if(c!=2) s1.insert(((c-2)*w)%MOD);
                ans+=f(c-2,w);
                s1.insert(w%MOD);
            }else if(c == 2) {
                s1.insert(((c)*w)%MOD);
                ans+=f(c,w);
            }else {
                s1.insert(((c-2)*w)%MOD);
                ans+=f(c-2,w);
                s1.insert(w%MOD);
                s1.insert(w%MOD);
            }
        }
    }
    // for(auto x:s1) cout<<x<<" ";
    // cout<<"\n";
    
    while(s1.size() >= 2){
        auto it = s1.begin();
        ll a=*it;
        s1.erase(it);
        it = s1.begin();
        ll b=*(it);
        s1.erase(it);
        // cout<<a<<" "<<b<<" "<<(a%MOD + b%MOD)%MOD<<"\n";
        ans+=(a%MOD + b%MOD)%MOD;
        s1.insert((a%MOD + b%MOD)%MOD);
    }
    cout<<ans<<"\n";
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