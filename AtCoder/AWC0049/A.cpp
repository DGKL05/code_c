#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void test(){
    int n=0;ll m=0;
    cin>>n>>m;
    vector<ll>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        m = (m*arr[i]/100);
    }
    cout<<m<<"\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin>>T;
    while(T--) test();
    return 0;
}