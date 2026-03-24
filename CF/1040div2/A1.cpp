#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    ll ans=0;ll num=0;
    for(int i=0;i<n;i++){
        int x=0;
        cin>>x;
        if(x==0) num++;
        ans+=x;
    }
    cout<<ans+num<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}