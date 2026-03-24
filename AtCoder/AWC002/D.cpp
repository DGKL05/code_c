#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int m=0;
    cin>>n>>m;
    vector<ll>a(n) , b(m);
    for(auto &x:a) cin>>x;
    for(auto &x:b) cin>>x;
    sort(a.begin() , a.end());
    sort(b.begin() , b.end());
    int j=0;
    int ans=0;
    for(int i=0;i<n;i++){
        while(j<m && b[j] < a[i]){
            j++;
        }
        if(j >= m) break;
        ans++;
        j++;
    }
    cout<<ans<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}