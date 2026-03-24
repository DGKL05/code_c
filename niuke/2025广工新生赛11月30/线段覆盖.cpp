#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    multiset<ll>s1;
    vector<ll>arr(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=2;i<=n;i++){
        s1.insert((arr[i] - arr[i-1]));
    }
    vector<ll>ans(n+1,0);
    int k = n;
    for(int i=k-1;i>=2;i--){
        ans[i] = ans[i+1] + *s1.begin();
        s1.erase(s1.begin());
    }
    ans[1] = arr[n] - arr[1];
    for(int i=1;i<=k;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
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