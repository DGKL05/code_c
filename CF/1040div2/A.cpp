#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    vector<ll>v1;
    vector<int>sum(51);
    ll ans=0;
    for(int i=0;i<n;i++){
        ll num=0;
        cin>>num;
        sum[num]++;
        if(num>=0) ans+=num,v1.push_back(num);
    }
    vector<int>q(51,-1);
    ll a=1e18;
    for(int i=0;i<=50;i++){
        if(sum[i]<a){
            q[i]=sum[i];
            a=sum[i];
        }
        // cout<<q[i]<<" ";
    }
    sort(v1.begin(),v1.end());
    // ll num=0;
    for(int i=0;i<51;i++){
        if(q[i]==-1) continue;
        ll temp=q[i]*(i+1);
        for(int j=i+1;j<51;j++) temp+=1LL*sum[i]*i;
        ans=max(temp,ans);
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