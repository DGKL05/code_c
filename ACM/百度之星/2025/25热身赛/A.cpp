#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int p=0;
    cin>>n>>p;
    map<int,int>m1;
    for(int i=0;i<n;i++){
        m1[i]=p;
    }
    for(auto [l,r] : m1){
        cout<<l<<" "<<r<<"\n";
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}