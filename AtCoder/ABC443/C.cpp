#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;ll Time=0;
    cin>>n>>Time;;
    vector<ll>arr(n);
    ll ans=0;
    ll time=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        if(arr[i] >= time){
            ans+=arr[i] - time;
            // cout<<arr[i]<<" "<<time<<" "<<arr[i] - time<<"\n";
            time = arr[i] + 100;
        }
    }
    if(time<Time){
        ans+=Time - time;
    }
    cout<<ans<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}