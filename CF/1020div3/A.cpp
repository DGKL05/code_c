#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    string s1;
    cin>>n>>s1;
    ll ans=0;
    for(char x:s1){
        if(x=='1') ans++;
    }
    ll num=0;
    for(int x:s1){
        if(x=='1') num+=ans-1;
        else num+=ans+1;
    }
    cout<<num<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int t=0;
    cin>>t;
    while(t--) test();
    return 0;
}