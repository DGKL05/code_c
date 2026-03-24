#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    ll ans=0;
    ll ans1=0;
    for(int i=0;i<n;i++){
        int num=0;
        cin>>num;
        if(num==-1) ans1++;
        if(num == 0) ans++;
    }
    if(ans1%2==1) ans+=2;
    cout<<ans<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}