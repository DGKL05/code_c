#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    ll num = 0;
    for(int i=2;i*i<=n;i++){
        if(num % i == 0){
            cout<<"No\n";
            return ;
        }
    }
    cout<<"Yes\n";
}   

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}