#include<bits/stdc++.h>

using namespace std;

void test(){
    int n=0;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    // for(auto x:arr) cout<<x<<" ";
    // cout<<"\n";
    cout<<0<<" ";
    for(int i=1;i<n;i++){
        int ans=0;
        for(int j=0;j<i;j++){
            if(arr[j] < arr[i]) ans++;
        }
        cout<<ans<<" ";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin>>T;
    while(T--) test();
    return 0;
}