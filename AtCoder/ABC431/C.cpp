#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int m=0;int k=0;
    cin>>n>>m>>k;
    vector<ll>h(n,0);
    vector<ll>b(m,0);
    for(int i=0;i<n;i++) cin>>h[i];
    for(int i=0;i<m;i++) cin>>b[i];
    sort(h.begin(),h.end());
    sort(b.begin(),b.end());
    int ans=0;
    int j=0;
    for(int i=0;i<n;i++){
        if(j == m) break;
        while(j<m && b[j] < h[i]){
            j++;
        }
        if(j == m) break;
        // cout<<j<<" ";
        j++;
        ans++;
    }
    // cout<<"ans = "<<ans<<"\n";
    cout<< ( ans >= k ? "Yes" : "No" ) << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}