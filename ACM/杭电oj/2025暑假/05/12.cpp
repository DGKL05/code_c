#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    
    vector<ll>a(n),b(n);
    for(auto &x:a) cin>>x;
    for(auto &x:b) cin>>x;
    vector<ll>arr1(n),arr2(n);
    for(int i=0;i<n;i++){
        arr1[i]=a[i]+b[i];
        arr2[i]=a[i]-b[i];
    }
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
    ll min1=1e18;ll min2=1e18;
    for(int i=0;i<n-1;i++){
        ll num1=arr1[i+1]-arr1[i];
        ll num2=arr2[i+1]-arr2[i];
        min1=min(min1,num1);
        min2=min(min2,num2);
    }
    cout<<min(min1,min2)<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}