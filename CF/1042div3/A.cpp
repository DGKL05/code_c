#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    vector<int>v1(n),v2(n);
    for(auto &x :v1) cin>>x;
    for(auto &x:v2) cin>>x;
    ll ans=0;
    for(int i=0;i<n;i++){
        if(v1[i]>v2[i]){
            ans+=(v1[i]-v2[i]);
        }
    }
    cout<<ans+1<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}