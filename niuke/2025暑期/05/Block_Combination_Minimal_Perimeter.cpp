#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    ll n=0;
    cin>>n;
    // if(n==1){
    //     cout<<"4\n";
    //     return ;
    // }
    if(n%2==1){
        cout<<1LL*((n-1)/2+1)*2+n*2<<"\n";
    }else{
        cout<<1LL*(n+1)*2+n<<"\n";
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}