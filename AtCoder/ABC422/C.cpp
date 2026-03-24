#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    ll a=0;ll b=0; ll c=0;
    cin>>a>>b>>c;
    cout<<min({a,c,(a+b+c)/3})<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}