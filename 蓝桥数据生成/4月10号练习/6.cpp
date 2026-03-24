#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const int N = 5*1e5+5;

ll arr[N];
ll sum[N];
int main()
{
    int n=0;int q=0;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>sum[i];
    arr[1]=sum[1];
    // cout<<"arr_1 = "<<arr[1];
    for(int i=2;i<=n;i++){
        arr[i]=sum[i]-sum[i-1];
    }
    
    while(q--){
        int l=0;int r=0;ll x=0;
        cin>>l>>r>>x;
        arr[l]+=x;
        if(r+1<=n) arr[r+1]-=x;
    }
    //cout<<"arr_1 = "<<arr[1];
    ll ans=0;
    for(int i=1;i<=n;i++){
        ans+=arr[i];
        if(ans<0) cout<<"0 ";
        else cout<<ans<<" ";
    }
    return 0;
}