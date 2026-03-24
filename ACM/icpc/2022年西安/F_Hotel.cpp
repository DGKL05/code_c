#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void test()
{
    int n=0;int dan=0;int shuan=0;
    cin>>n>>dan>>shuan;
    ll ans=0;
    for(int i=0;i<n;i++){
        string s1;
        cin>>s1;
        map<char,int>m1;
        for(auto x:s1) m1[x]++;
        ll max_num =-1;
        for(auto [l,r] : m1){
            max_num = max((ll)r,max_num);
        }
        // cout<<"max = "<<max_num<<"\n";
        if(max_num == 1){
            ans+=min(1LL*3*dan,1LL*3*shuan);
        }else {
            ans+=min({1LL*3*dan,1LL*(dan+shuan),1LL*2*shuan});
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