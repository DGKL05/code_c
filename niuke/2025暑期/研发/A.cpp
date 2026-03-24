#include<bits/stdc++.h>
using namespace std;

using ll =long long;
const ll top = 1e9;
bool check(ll x,ll y){
    if((y-x)%10 == (y+x)%10 && y<=top && x<=top && y>=x && x>=1 && y>=1) return true;
    else return false;
}

void test()
{
    ll x=0;ll y=0;
    cin>>x>>y;
    ll ans=1e18;
    for(int i=0;i<=10;i++){
        for(int j=0;j<=10;j++){
            if(check(x+i,y+j)){
                ans=min(ans,(ll)i+j);
            }
        }
    }
    for(int i=0;i<=10;i++){
        for(int j=0;j<=10;j++){
            if(check(x+i,y-j)){
                ans=min(ans,(ll)i+j);
            }
        }
    }
    for(int i=0;i<=10;i++){
        for(int j=0;j<=10;j++){
            if(check(x-i,y+j)){
                ans=min(ans,(ll)i+j);
            }
        }
    }
    for(int i=0;i<=10;i++){
        for(int j=0;j<=10;j++){
            if(check(x-i,y-j)){
                ans=min(ans,(ll)i+j);
            }
        }
    }
    cout<<ans<<"\n";
}

int main()
{
    int T=1;
    // cout<<(int)('z'-97)<<"\n";
    cin>>T;
    while(T--) test();
    return 0;
}