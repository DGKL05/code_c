#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    ll n=0;ll m=0;
    cin>>n>>m;
    cout<<(m+1)/2+(n-1)*(m/2)<<"\n";

}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}