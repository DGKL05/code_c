#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    ll a=0;ll b=0;
    ll x=0;ll k=0;
    cin>>k>>x;
    a=pow(2,k);
    b=pow(2,k);
    ll y=(a-x)+b;
    ll num=0;
    vector<int>ans;
    while(y!=x){
        if(x>y){
            x-=y;
            y=1LL*y*2;
            ans.push_back(2);
            num++;
        }else {
            y-=x;
            x=1LL*2*x;
            ans.push_back(1);
            num++;
        }
    }
    cout<<num<<"\n";
    for(int i=num-1;i>=0;i--){
        cout<<ans[i]<<" ";
    }
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