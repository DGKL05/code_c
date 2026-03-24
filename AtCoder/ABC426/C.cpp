#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    map<int,int>m1;
    int n=0;int q=0;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        m1[i]=1;
    }
    while(q--){
        int x=0;int y=0;
        cin>>x>>y;
        ll ans=0;
        auto it = m1.begin();
        while(it!=m1.end()){
            if(it->first <= x){
                ans+=it->second;
                m1[y]+=it->second;
                it = m1.erase(it);
            }else break;
        }
        cout<<ans<<"\n";
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}