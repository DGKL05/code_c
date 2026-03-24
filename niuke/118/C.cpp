#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    vector<int>v1(n);
    for(auto &x:v1) cin>>x;
    ll ans=0;
    // map<int,int>m1;
    //4 5 3 1 6
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(2*v1[i]<=v1[j] && (abs(j-i)>1)){
                // cout<<i+1<<" "<<j+1<<" "<<abs(j-i)-1<<"\n";
                ans+=(abs(j-i)-1);
            }
        }
    }
    cout<<ans<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}