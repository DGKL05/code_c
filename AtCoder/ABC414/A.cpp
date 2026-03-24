#include<bits/stdc++.h>
using namespace std;
using ll =long long;
int l,r;int ans=0;
void test()
{
    int l1=0;int r1=0;
    cin>>l1>>r1;
    if(l1<=l && r1>=r) ans++;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    
    cin>>T;
    cin>>l>>r;
    while(T--) test();
    cout<<ans<<"\n"; 
    return 0;
}