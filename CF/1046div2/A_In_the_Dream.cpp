#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int a=0;int b=0; int c=0;int d=0;
    cin>>a>>b>>c>>d;
    int min1=min(a,b);
    int max1=max(a,b);
    if((min1+1)*2 < max1){
        cout<<"NO\n";
        return ;
    }
    c-=a;d-=b;
    min1=min(c,d);
    max1=max(c,d);
    if((min1+1)*2 < max1){
        cout<<"NO\n";
        return ;
    }
    cout<<"YES\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}