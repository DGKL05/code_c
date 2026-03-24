#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    for(int i=1;i<=n;i+=2){
        cout<<i<<" ";
    }
    for(int i=4;i<=n;i+=2){
        cout<<i<<' ';
    }
    if(n>=2) cout<<2<<' ';
    cout<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}