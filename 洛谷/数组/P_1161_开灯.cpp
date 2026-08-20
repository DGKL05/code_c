#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void test(){
    int n=0;
    cin>>n;
    map<ll,int>m1;
    for(int i=0;i<n;i++){
        double a =0.00;
        int t=0;
        cin>>a>>t;
        for(int j=1;j<=t;j++){
            m1[ll(1LL*(a*j))]++;
            // cout<<ll(1LL*(a*j))<<" "<<1.000000*(a*j)<<"\n";
        }
    }
    for(auto [l,r] : m1){
        if(r&1) {
            cout<<l<<"\n";
            // return ;
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