#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int m=0;int q=0;int p=0;
    cin>>n>>m>>p>>q;
    if(n%p==0){
        if(n/p*q==m){
            cout<<"YES\n";
        }else cout<<"NO\n";
    }else{
        cout<<"YES\n";
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int t=0;
    cin>>t;
    while(t--) test();
    return 0;
}