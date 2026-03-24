#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    int num = n%10;
    while(n){
        if(n%10 != num){
            cout<<"No\n";
            return ;
        }
        n/=10;
    }
    cout<<"Yes\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}