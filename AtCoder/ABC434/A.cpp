#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int w=0;int b=0;
    cin>>w>>b;
    w*=1000;
    cout<< (w%b == 0 ? w/b + 1 : w/b + 1) <<"\n";
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