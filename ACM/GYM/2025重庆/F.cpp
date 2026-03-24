#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    ll a,b,c;
    cin>>a>>b>>c;
    if(a>b){
        cout<<"Win\n";
        return ;
    }else if(b<c){
        cout<<"WIN\n";
        return ;
    }else {
        cout<<"nowin\n";
        return ;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}