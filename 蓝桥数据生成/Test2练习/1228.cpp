#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
const int N = 1e5;
ll arr[N];
int main()
{
    int n=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(int i=1;i<n;i++) arr[i]=arr[i-1]+arr[i];
    ll num=0;
    for(int i=n-1;i>0;i--){
        // cout<<arr[i]<<' ';
        num+=arr[i];
    }
    cout<<num<<"\n";
    return 0;
}