#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const int N = 3*1e5+5;

int low[N];
// ll arr[N];

int main()
{
    int n=0;
    cin>>n;
    vector<ll>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    low[0]=arr[0];
    int index=0;
    for(int i=1;i<n;i++){
        if(arr[i]>low[index]) low[++index] = arr[i];
        else {
            int *it =  lower_bound(low,low+index,arr[i]);
            low[it-low] = arr[i];
            // cout<<arr[i]<<" "<<it-low+1<<"\n";
        }
    }
    cout<<index+1<<"\n";
    return 0;
}