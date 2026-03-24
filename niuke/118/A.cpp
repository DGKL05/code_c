#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int a,b,c;
    cin>>a>>b>>c;
    cout<<1LL*(a*79+b*89+c*100)<<" "<<1LL*(a*60+b*80+c*90)<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}