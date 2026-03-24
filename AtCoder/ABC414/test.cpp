#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int t=1;
    cin>>t;
    while(t--){
        int n=0;
        cin>>n;
        map<int,int>m1;
        for(int i=0;i<n;i++) {
            int num=0;
            cin>>num;
            m1[num]++;
        }
        ll ans=0;
        for(auto [l,r] : m1){
            if(r!=1){
                ans+=r-1;
                m1[l+1]=r-1;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}