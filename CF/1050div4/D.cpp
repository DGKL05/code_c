#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    ll ans=0;
    vector<ll>arr(n);
    int jshu=0;int oshu=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]%2) jshu++;
        else oshu++;
    }
    if(jshu == 0){
        cout<<"0\n";
        return ;
    }
    bool fa=true;
    // jshu--;
    int num=0;
    sort(arr.begin(),arr.end());
    for(int i=n-1;i>=0;i--){
        if(arr[i]%2==0) ans+=arr[i];
        else {
            if(num<((jshu+1)/2) ) ans+=arr[i],fa=false;
            // cout<<"j / 2 = " <<jshu/2<<"\n";
            num++;
        }
    }
    cout<<ans<<'\n';
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}