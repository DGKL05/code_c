#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void test()
{
    ll p =0;ll k =0;
    cin>>p>>k;
    vector<vector<ll>>arr(p,vector<ll>(k*p));
    for(int i=0;i<p;i++){
        for(int j=0;j<k*p;j++){
            cin>>arr[i][j];
        }
    }
    vector<ll>ans(k*p);
    for(int i=0;i<k*p;i++){
        // cout<<i<<" ";
        for(int j=0;j<p;j++){
            ans[i] += arr[j][i];
        }
    }
    int idx = 0;
    for(int i=0;i<k*p;i++){
        cout<<ans[i]<<" ";
        idx++;
        if(idx == k && i != (p*k-1)){
            idx = 0;
            cout<<"\n";
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T = 1;
    // cin>>T;
    while(T--) test();
    return 0;
}