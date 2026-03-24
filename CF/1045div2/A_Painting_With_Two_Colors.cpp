#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    ll n=0;ll a=0;ll b=0;
    cin>>n>>a>>b;
    if(a<=b){
        if(n%2==b%2){
            cout<<"YES\n";
        }else {
            cout<<"NO\n";
        }
    }else {
        if(n%2==b%2 && b%2==a%2){
            cout<<"YES\n";
        }else cout<<"NO\n";
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