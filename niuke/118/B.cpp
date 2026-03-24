#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int a,b,n,k;
    cin>>a>>b>>n>>k;
    for(int i=0;i<=n;i++){
        if(1LL*(a*i+b*(n-i))==k){
            cout<<"YES\n";
            return ;
        }
    }
    cout<<"NO\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}