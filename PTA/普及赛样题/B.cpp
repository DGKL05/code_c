#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int x=0;int y=0;
    cin>>x>>y;
    cout<<100*100/2 - y * x/2 - (100 - x)*(100-y)/2 -(100-x)*(y)<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}