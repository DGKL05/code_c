#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    ll a=0; ll b=0;
    cin>>a>>b;
    ll a1=min(a,b);
    ll b1=max(a,b);
    if(a==b){
        cout<<"0\n";
        return ;
    }
    if(b1%a1==0){
        cout<<1<<"\n";
    }else {
        cout<<"2\n";
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