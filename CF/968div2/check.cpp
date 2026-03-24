#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const int l =1e9;
void test()
{
    ll x=0;ll y=0;
    for(int i=0;i<999;i++){
        ll x1=0;ll y1=0;
        cin>>x1>>y1;
        x+=x1;y+=y1;
    }
    cout<<x/999<<' '<<y/999<<"\n";
}

int main()
{
    int t=1;
    // cin>>t;
    while(t--) test();
    return 0;
}