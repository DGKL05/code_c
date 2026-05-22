#include<bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

void test()
{
    int n=0;
    cin>>n;
    multiset<ll>s1;
    for(int i=0;i<n;i++){
        ll a=0;
        cin>>a;
        s1.insert(a);
    }
    ll ans = 0;
    while(s1.size() > 1){
        auto it1 = s1.end();
        it1--;
        auto it2 = s1.end();
        it2--;
        it2--;
        ll a = *it1;
        ll b = *it2;
        ans += max(a , b);
        s1.erase(it1);
        s1.erase(it2);
        s1.insert(1LL*(a+b));
    }
    cout<<ans<<"\n";
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