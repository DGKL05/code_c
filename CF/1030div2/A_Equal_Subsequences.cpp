#include<bits/stdc++.h>
using namespace std;
using ll =long long;
// 10101
void test()
{
    int n=0;int k=0;
    cin>>n>>k;
    for(int i=0;i<k;i++) cout<<"1";
    for(int i=0;i<n-k;i++) cout<<"0";
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