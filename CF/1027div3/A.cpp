#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    ll n=0;
    cin>>n;
    if(n==0){
        cout<<"0 0\n";
        return ;
    }
    for(int i=1;i*i<=20000;i++){
        if((ll)(i*i)==(ll)n){
            cout<<1<<' '<<(i-1)<<"\n";
            return ;
        }
    }
    cout<<"-1\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}