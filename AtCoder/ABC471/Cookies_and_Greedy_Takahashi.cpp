#include<bits/stdc++.h>

using namespace std;
using ll = long long;

struct node{
    ll net;
    ll dang;
};

node check(set<ll> &s1 , ll idx){
    ll temp = 1e18;
    ll ans=0;
    auto it = s1.upper_bound(idx);
    if(it != s1.end()){
        temp = abs((*it) - idx);
        ans = *it;
    }
    if(it != s1.begin()){
        auto x = it;
        x--;
        if((abs(idx - (*x)) <= temp )){
            ans = *x;
            temp = abs(idx - (*x));
        }
    }
    node n1;
    n1.net = ans;
    n1.dang = temp;
    s1.erase(ans);
    return n1;
}

void test(){
    int n=0;
    cin>>n;
    set<ll>s1;
    int be = 1e18;
    for(int i=0;i<n;i++){
        ll num =0;
        cin>>num;
        s1.insert(num);
    }
    ll idx = 0;
    ll ans = 0;
    for(int i=0;i<n;i++){
        node n1 = check(s1,idx);
        // cout<<n1.net<<" "<<n1.dang<<"\n";
        idx = n1.net;
        ans += n1.dang;
    }
    cout<<ans<<"\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin>>T;
    while(T--) test();
    return 0;
}