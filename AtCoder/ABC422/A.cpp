#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int a=0;int b=0;char c;
    cin>>a>>c>>b;
    if(b==8){
        cout<<a+1<<c<<1<<"\n";
    }else {
        cout<<a<<c<<b+1<<"\n";
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
