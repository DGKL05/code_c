#include<bits/stdc++.h>
using namespace std;
using ll =long long;
vector<int>arr,l,r,h;
int n=0;int m=0;

bool check(int mid){
    vector<int>sum(n);
    for(int i=0;i<mid;i++){
        sum[l[i]]+=h[i];
        if(r[i]!=(n-1)) sum[r[i]+1]-=h[i];
    }
    for(int i=1;i<n;i++) sum[i]+=sum[i-1];
    // for(int i=0;i<n;i++){
    //     cout<<sum[i]<<" ";
    // }
    // cout<<"\n";
    for(int i=0;i<n;i++){
        if((arr[i]-sum[i])<=0) return true;
    }
    return false;
}

void test()
{
    cin>>n>>m;
    arr.resize(n);
    l.resize(m);
    r.resize(m);
    h.resize(m);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<m;i++){
        cin>>l[i]>>r[i]>>h[i];
        l[i]--;r[i]--;
    }
    int L=1;int R=m;
    int ans=0;
    while(L<=R){
        int mid=(L+R)>>1;
        // cout<<mid<<"\n";
        if(check(mid)){
            // cout<<mid<<"\n";
            ans=mid;
            R=mid-1;
        }else L=mid+1;
    }
    cout<<ans<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}