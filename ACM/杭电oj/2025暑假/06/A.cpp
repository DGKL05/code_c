#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    ll num=0;ll min_num=1e18;ll ans=0;ll max_num=-1e18;
    for(int i=0;i<n;i++){
        ll x=0;
        cin>>x;
        if(x==0) ans++;
        else if(x<0) num++,max_num=max(max_num,x);
        else min_num=min(min_num,x);
    }
    if(ans){
        cout<<ans<<"\n";
        return ;
    }
    if(num%2==1){
        ll temp=1e18;
        temp=min(abs(max_num)+1,min_num+1);
        cout<<ans+temp<<"\n";
        return ;
    }
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