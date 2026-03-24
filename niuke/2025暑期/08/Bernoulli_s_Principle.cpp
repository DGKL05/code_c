#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;ll H=0;
    cin>>n>>H;
    multimap<ll,int>m1;
    for(int i=0;i<n;i++){
        ll h=0;
        cin>>h;
        m1.insert(pair<ll,int>((1LL*h*(H-h)),i+1));
    }
    for(auto [l,r] : m1){
        cout<<r<<" ";
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