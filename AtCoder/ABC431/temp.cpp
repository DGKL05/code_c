#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    ll n=0;ll k=0;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++) arr[i] = i+1;
    bool fa1 = false;
    int k1 =0;
    do{
        k1++;
        bool fa = true;
        vector<int>sum(n,0);

        sum[0] = arr[0];
        for(int i=1;i<n;i++){
            sum[i] = sum[i-1] + arr[i];
        }
        int num = sum[k-1];
        // for(int i=0;i<n;i++){
        //     cout<<arr[i]<<" ";
        // }cout<<"\n";

        cout<< "\nnum = " <<sum[k-1] <<" ";
        for(int i=1;i<=n-k;i++){
            cout<<sum[i+k-1] - sum[i-1]<<" ";
            if( (sum[i+k-1] - sum[i-1]) %2 != num%2) {
                fa = false;
                continue;
            }
        }
        if(fa) {
            fa1 = true;
            break;
        }
    }while( next_permutation(arr.begin() , arr.end()) && k1<1);

    if(fa1){
        cout<<"Yes\n";
        for(auto x:arr) cout<<x<<" ";
        cout<<"\n";
    }else cout<<"No\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}