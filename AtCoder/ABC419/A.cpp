#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    string s1;
    cin>>s1;
    if(s1=="red"){
        cout<<"SSS\n";
    }else if(s1=="blue"){
        cout<<"FFF\n";
    }else if(s1=="green"){
        cout<<"MMM\n";
    }else cout<<"Unknown\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}