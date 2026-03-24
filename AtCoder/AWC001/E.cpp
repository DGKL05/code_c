#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{  
    int n=0;int k=0;
    cin>>n>>k;
    vector<ll>arr(n);
    multiset<ll>s1;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(i<k) s1.insert(arr[i]);
    }
    auto it = s1.end();
    it--;
    ll ans = *it - *s1.begin();
    for(int i=k;i<n;i++){
        s1.insert(arr[i]);
        s1.erase(s1.find(arr[i-k]));
        auto it = s1.end();
        it--;
        ans =  max(*it - *s1.begin() , ans);
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