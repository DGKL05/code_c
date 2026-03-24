#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int s=0;
    cin>>n>>s;
    int ans=0;int num=0;
    for(int i=0;i<n;i++){
        int r=0;int k=0;
        cin>>r>>K;
        if(r==1) ans++;
        num+=k;
    }
    if(2*r>=n) cout<<"1 ";
    else cout<<"0 ";
    if(num-50>=s) cout<<"1\n";
    else cout<<"0\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}