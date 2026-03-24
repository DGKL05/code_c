#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    ll a=0; ll b=0 ;ll c=0;
    cin>>a>>b>>c;
    cout<<"100\n";
    for(int i=0;i<50;i++) cout<<a<<" ";
    for(int i=0;i<(45);i++) cout<<b<<" ";
    for(int i=0;i<4;i++) cout<<c<<" ";
    cout<<c+1<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}