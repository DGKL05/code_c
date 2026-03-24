#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    vector<ll>v1(10);
    ll ans=0;ll num=0;
    for(int i=0;i<10;i++){
        cin>>v1[i];
        if(i%2==1&&i!=9) num+=v1[i];
    }
    ans+=v1[0];ans+=v1[4];ans+=v1[8];
    ll num1=v1[2]+v1[6];
    if(num1>num){
        ans+=num;
        num-=num1;
        
    }else if(num1==num){
        ans+=num1;
        ans+=(v1[9]/2);
        cout<<ans<<"\n";
    }else {

    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}