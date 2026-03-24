#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int m=0;int q=0;int ans=0;
    cin>>n;
    vector<int>v1(n);
    for(int i=0;i<n;i++){
        cin>>v1[i];
        if(i&&abs(v1[i])>=abs(v1[0]))ans++;
    }
    if(n%2==0){
        if(ans>=(n/2-1)) cout<<"YES\n";
        else cout<<"NO\n";
    }else{
        if(ans>=n/2) cout<<"YES\n";
        else cout<<"NO\n";
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int t=0;
    cin>>t;
    while(t--) test();
    return 0;
}