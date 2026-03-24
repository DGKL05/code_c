#include<bits/stdc++.h>
using namespace std;
using ll =long long;

const ll MOD = 1e9+7;

void test()
{
    string ans;
    cin>>ans;
    ll a=0,c=0,m=0,ac=0,cm=0,acm=0;
    for(auto x:ans){
        if(x == 'a'){
            acm = (acm + cm) % MOD;
            ac = (ac + c) % MOD;
            a = (a + 1) % MOD;
        }
        if(x == 'M') {
            acm = (acm + ac) % MOD;
            cm = (cm + c) % MOD;
            m = (m + 1) % MOD;
        }
        if(x == 'C'){
            ac = (ac + a) % MOD;
            c = (c + 1) % MOD;
        }
        if(x == 'c'){
            cm = (cm + m) % MOD;
            c = (c + 1) % MOD;
        }
        if(x == 'A'){
            a = (a + 1) % MOD;
        }
        if(x == 'm'){
            m = (m + 1) % MOD;
        }
        cout<<acm%MOD<<" ";
    }
    cout<<"\n";
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