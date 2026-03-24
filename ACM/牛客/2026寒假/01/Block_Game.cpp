#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    int k=0;
    cin>>k;
    vector<int>arr(n+1,k);
    for(int i=0;i<n;i++) cin>>arr[i];
    int ans=arr[0] + k;
    for(int i=0;i<n;i++){
        ans = max(arr[i]+arr[i+1],ans);
    }
    cout<<ans<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}
