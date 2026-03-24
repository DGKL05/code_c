#include<bits/stdc++.h>
using namespace std;
using ll =long long;
// 3-4 5-6-1-2
void test()
{
    int n=0;
    cin>>n;
    vector<int>v1(n);
    int min_n=1e8;
    for(int i=0;i<n;i++){
        ll num=0;
        cin>>num;
        v1[i]=num;
        min_n=min(v1[i],min_n);
    }
    ll ans=0;int num=0;
    if(min_n>=2){
        cout<<"YES\n";
        return ;
    }
    for(int i=0;i<n;i++){
        if(v1[i] == 0){
            cout<<"NO\n";
            return ;
        }
        ans+=v1[i];
    }
    
    if(ans>=1LL*2*(n-1)){
        cout<<"YES\n";
        return ;
    }
    cout<<"NO\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    // cout<<((-16)%4)<<"\n";
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}