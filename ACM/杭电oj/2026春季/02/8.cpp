#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    vector<ll>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=0;
    ll sum=0;
    ll num=0;
    for(int i=0;i<n-1;i++){
        sum+=arr[i];
        if(sum < num){
            num = sum;
            ans = i+1;
        }
    }
    cout<<ans+1<<"\n";
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