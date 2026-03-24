#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int x=0;int y=0;
    cin>>x>>y;
    cout<<((x+y)%12==0?12:(int)(x+y)%12)<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}