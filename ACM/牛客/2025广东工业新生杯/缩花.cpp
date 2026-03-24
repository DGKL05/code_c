#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n = 0;
    cin>>n;
    vector<int> a ,d(n+1);
    int ans =-1;
    for (int i=0;i<n-1;i++) {
        int u,v;
        cin>>u>>v;
        d[u]++,d[v]++;
        if (d[u] == 2) ans++ ,a.push_back(u);
        if (d[v] == 2) ans++ ,a.push_back(v);
    }
 
    if (ans <= 0) {
        cout<<0<<endl;
    }else {
        cout<<ans<<endl;
        cout<<a[0]<<' '<<a[1]<<endl;
         
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}