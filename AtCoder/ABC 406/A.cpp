#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a<c){
        cout<<"No\n";
        return ;
    }else {
        if(b<d && a==c){
            cout<<"No\n";
            return;
        }
    }
    cout<<"Yes\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}