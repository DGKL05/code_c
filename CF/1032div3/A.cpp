#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int s=0;
    cin>>n>>s;
    vector<int> v1(n);
    for(int i=0;i<n;i++) cin>>v1[i];
    if(n==1){
        if(v1[0] == s) cout<<0<<"\n";
        else cout<<abs(v1[0]-s)<<"\n";
        return ;
    }
    if(v1[n-1]<=s){
        cout<<s-v1[0]<<"\n";
    }else if(v1[0]>=s){
        cout<<v1[n-1]-s<<"\n";
    }else {
        int mx=max(v1[n-1]-s,s-v1[0]);
        int mi=min(v1[n-1]-s,s-v1[0]);
        cout<<2*mi+mx<<"\n";
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