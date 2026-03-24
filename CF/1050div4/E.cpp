#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int k=0;
    cin>>n>>k;
    vector<int>arr(n+1);
    vector<int>max_cnt(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        max_cnt[arr[i]]++;
    }
    for(int i=1;i<=n;i++){
        if(max_cnt[i]!=0 && max_cnt[i]%k!=0){
            cout<<"0\n";
            return ;
        }
    }
    for(int i=1;i<=n;i++){
        max_cnt[i]/=k;
    }
    vector<int>cnt(n+1);
    int l=1;ll ans=0;
    for(int r=1;r<=n;r++){
        cnt[arr[r]]++;
        while(cnt[arr[r]] > max_cnt[arr[r]] && l<=r){
            cnt[arr[l]]--;
            l++;
        }
        ans+=(r-l+1);
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