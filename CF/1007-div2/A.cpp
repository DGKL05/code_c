#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    ll k=0;
    cin>>k;
    if(k==1){
        cout<<"Yes\n";
        return ;
    }
    if(k%3==1){
        cout<<"Yes";
    }else {
        cout<<"No";
    }
    cout<<"\n";
}

int main()
{
    int t=0;
    cin>>t;
    while(t--) test();
    return 0;
}