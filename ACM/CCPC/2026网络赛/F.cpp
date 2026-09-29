#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using i128 = __int128_t;

vector<ll>cand;

ll calL(ll l,ll k,ll T){
    i128 x=(i128)l*k;
    return (ll)((x+T-1)/T);
}

ll calR(ll r,ll k,ll T){
    i128 x=(i128)r*k;
    return (ll)(x/T);
}

bool check(ll k,ll T,vector<pair<ll,ll>>&a,vector<pair<ll,ll>>&b){
    ll cnt1=0;
    for(auto [l,r]:a){
        ll L=calL(l,k,T);
        ll R=calR(r,k,T);
        L=max(L,1LL);
        R=min(R,k);
        if(L>R) continue;
        cnt1+=R/6-(L-1)/6;
    }
    if(cnt1!=k/6) return false;
    ll cnt2=0;
    for(auto [l,r]:b){
        ll L=calL(l,k,T);
        ll R=calR(r,k,T);
        L=max(L,1LL);
        R=min(R,k);
        if(L>R) continue;
        ll all=R-L+1;
        ll six=R/6-(L-1)/6;
        cnt2+=all-six;
    }
    return cnt2==k-k/6;
}

void test(){
    int n,m;
    cin>>n>>m;
    vector<pair<ll,ll>>a(n);
    vector<pair<ll,ll>>b(m);
    for(int i=0;i<n;i++) cin>>a[i].first>>a[i].second;
    for(int i=0;i<m;i++) cin>>b[i].first>>b[i].second;
    int q;
    cin>>q;
    while(q--){
        ll T;
        cin>>T;
        ll ans=-1;
        for(ll k:cand){
            if(k>T) break;
            if(check(k,T,a,b)){
                ans=k;
                break;
            }
        }
        cout<<ans<<"\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    const ll INF=1000000000000000000LL;
    for(i128 x=2;x<=INF;x*=2){
        for(i128 y=3;x*y<=INF;y*=3){
            cand.push_back((ll)(x*y));
        }
    }
    sort(cand.begin(),cand.end());
    cand.erase(unique(cand.begin(),cand.end()),cand.end());
    test();
    return 0;
}