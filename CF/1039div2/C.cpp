#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    vector<ll>v1(n);
    for(auto &x:v1) cin>>x;
    vector<ll>arr(n);
    arr[0] = v1[0];
    for(int i=1;i<n;i++){
        arr[i]=min(arr[i-1],v1[i]);
    }
    for(int i=1;i<n;i++){
        if(v1[i] >=1LL*2*arr[i]){
            cout<<"NO\n";
            return ;
        }
    }
    cout<<"YES\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}