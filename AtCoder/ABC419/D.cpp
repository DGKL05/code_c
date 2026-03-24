#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    int m=0;
    cin>>n>>m;
    string s1,t;
    cin>>s1>>t;
    vector<int>pre(n+1);
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        pre[l]++;
        if(r!=n) pre[r+1]--;
    }
    for(int i=1;i<n+1;i++){
        pre[i]=pre[i]+pre[i-1];
    }
    for(int i=1;i<=n;i++){
        if(pre[i]%2==0) cout<<s1[i-1];
        else cout<<t[i-1];
    }
    
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}