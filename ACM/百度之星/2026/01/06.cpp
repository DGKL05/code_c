#include<bits/stdc++.h>
using namespace std;
using ll = long long;

pair<ll,ll> get(ll a,ll b,ll c){
    if(c == 0) return {0,a};
    if(c == 1 && a < b) return {0,a};
    if(c%2 == 0 || a < b) return {c/2,a+1};
    return {c/2+1,a-b};
}

void test(){
    int n=0;
    cin>>n;

    ll x=0,y=0;

    for(int i=0;i<n;i++){
        ll a=0,b=0,c=0;
        cin>>a>>b>>c;

        auto [p,q] = get(a,b,c);

        x ^= p;
        y ^= q;
    }

    if(x || y) cout<<"First\n";
    else cout<<"Second\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T=1;
    cin>>T;

    while(T--) test();

    return 0;
}