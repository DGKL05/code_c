#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    vector<int>v1(n);
    for(int i=0;i<n;i++){
        cin>>v1[i];
    }
    sort(v1.begin(),v1.end());
    if((v1[0]+v1[n-1])%2==0){
        cout<<"0\n";
        return ;
    }
    int ans=1e9;
    int index=0;
    for(int i=1;i<n;i++){
        index++;
        // cout<<v1[i]<<' '<<v1[n-1]<<"\n";
        if((v1[i]+v1[n-1])%2==0){
            ans=index;
            break;
        }
    }
    // cout<<ans<<"\n";
    index=0;
    for(int i=n-2;i>=0;i--){
        index++;
        if((v1[i]+v1[0])%2==0){
            ans=min(ans,index);
        }
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
