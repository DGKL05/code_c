#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int k=0;int a=0;int b=0;

    cin>>n>>k>>a>>b;
    vector<bool>fa(n,false);
    vector<int>arr(n),brr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cin>>brr[i];
        if(arr[i]>=a && brr[i]>=b) fa[i]=true;
    }
    int ans=0;
    int temp=0;
    for(int i=0;i<n;i++){
        if(fa[i]) temp++;
        else temp=0;
        if(temp>=k) ans++;
    }
    cout<<ans<<'\n';
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}