#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int ans=0;
    int n=0;int q=0;
    cin>>ans>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>fa(n,false);
    cin>>q;
    while(q--){
        int idx=0;
        cin>>idx;
        idx--;
        if(fa[idx]) ans-=arr[idx];
        else ans+=arr[idx];
        fa[idx] = !fa[idx];
        cout<<ans<<"\n";
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