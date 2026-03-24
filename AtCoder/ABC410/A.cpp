#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    vector<int>v1(n);
    for(auto &x:v1) cin>>x;
    int k;
    cin>>k;
    int ans=0;
    for(auto x:v1) {
        if(x>=k) ans++;
    }
    cout<<ans<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}