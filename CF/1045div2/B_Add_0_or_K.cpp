#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;ll k=0;
    cin>>n>>k;
    vector<ll>arr(n);
    for(int i=0;i<n;i++){
        ll a=0;
        cin>>a;
        arr[i]=(a +(a % (k + 1) * k));
    }
    for(auto x:arr) cout<<x<<" ";
    cout<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}