#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int a=0;int b=0;
    cin>>a>>b;
    int ans = a-b;
    cout<<(ans <=0 ? 0 : ans) <<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}
