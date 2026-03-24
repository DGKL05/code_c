#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    vector<int>arr(n);
    for(auto &x:arr){
        cin>>x;
    }
    sort(arr.begin(),arr.end());
    int ans=0;
    for(int i=0;i<n;i+=2){
        ans=max(ans,abs(arr[i]-arr[i+1]));
    }
    cout<<ans<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}