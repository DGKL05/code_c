#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void test(){
    ll n=0;ll m=0;
    cin>>n>>m;
    vector<int>ans(10);
    for(ll i=n;i<=m;i++){
        string s1 = to_string(i);
        for(auto x:s1){
            ans[x-'0']++;
        }
    }
    for(auto x:ans) cout<<x<<" ";
    cout<<"\n";
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