#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int dan=0;int shuan=0;
    ll ans=0;
    for(int i=0;i<n;i++){
        string s1;
        cin>>s1;
        map<char,int>m1;
        for(auto x:s1) m1[x]++;
        auto it = m1.end();
        it--;
        if(it->second == 1){
            ans+=1LL*dan;
        }else {
            ans+=min(1LL*3*dan,dan+shuan);
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