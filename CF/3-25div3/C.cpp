#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    if(n%2==0) {
        cout<<"-1\n";
        return ;
    }
    for(int i=1;i<=n;i+=2){
        cout<<i<<' ';
    }
    for(int i=2;i<=n-1;i+=2){
        cout<<i<<" ";
    }
    cout<<"\n";
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);//std::cout.tie(0);
    int t=0;
    cin>>t;
    while(t--) test();
    return 0;
}