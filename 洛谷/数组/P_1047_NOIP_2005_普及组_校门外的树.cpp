#include<bits/stdc++.h>

using namespace std;

void test(){
    int n = 0;
    cin>>n;
    int m = 0;
    cin>>m;
    vector<int>arr(n+2,0);
    for(int i=0;i<m;i++){
        int a=0;int b=0;
        cin>>a>>b;
        arr[a]--;
        arr[b+1]++;
    }
    for(int i=1;i<n+1;i++){
        arr[i]+=arr[i-1];
    }
    int ans=0;
    for(int i=0;i<n+1;i++){
        if(arr[i] >= 0) ans++;
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin>>T;
    while(T--) test();
    return 0;
}