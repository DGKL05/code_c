#include<bits/stdc++.h>
using namespace std;
using ll =long long ;

void test()
{
    ll n=0;ll m=0;
    cin>>n>>m;
    if(n==m&&n*m==0){
        cout<<"No\n";
    }
    cout<<"Yes\n";
}

int main()
{
    int t=1;
    cin>>t;
    while(t--){
        test();
    }
}