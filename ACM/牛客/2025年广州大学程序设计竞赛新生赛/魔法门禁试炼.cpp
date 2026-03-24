#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<< ( (a < d && b == c) ? "YES\n" : "NO\n");
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