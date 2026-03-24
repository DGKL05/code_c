#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n;string s1;
    cin>>s1>>n;
    if(s1.size()>=n){
        cout<<"Yes\n";
    }else cout<<"No\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}