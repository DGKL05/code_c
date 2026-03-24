#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int a=0;int b=0;int c=0;int d=0;
    cin>>a>>b>>c>>d;
    if(c>=a){
        if(b>d){
            cout<<"Yes\n";
        }else cout<<"No\n";
    }else cout<<"No\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}