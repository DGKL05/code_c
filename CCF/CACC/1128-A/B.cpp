#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int k=0;
    cin>>n>>k;
    vector<ll>arr(n);
    for(auto &x:arr) cin>>x;
    multiset<ll>s1;
    s1.insert(arr[0]);
    for(int i=k+1;i<n;i++){
        s1.insert(arr[i]);
    }
    ll ans=1e18;
    auto tuo = s1.begin();
    auto wei = s1.end();wei--;
    ans = min(((*wei) - (*tuo)) , ans);
    // cout<<(*wei) <<" - "<<(*tuo)<<"\n";
    int j = k+1;
    for(int i=1;i<n-k-1;i++){
        s1.insert(arr[i]);
        s1.erase(s1.find(arr[j]));
        j++;
        tuo = s1.begin();
        wei = s1.end();
        wei--;
        ans = min(((*wei) - (*tuo)) , ans);
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