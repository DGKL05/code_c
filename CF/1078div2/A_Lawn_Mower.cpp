#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    ll n=0;ll w=0;
    cin>>n>>w;
    cout<<(n / w) * (w - 1) + (n % w)<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}