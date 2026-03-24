#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    string s1;
    cin>>s1;
    int ans=0;
    for(auto x:s1) {
        if(x == 'Y'){
            ans++;
        }
    }
    // cout<<"NO\n";
    cout<<( ans >= 2 ? "NO\n" : "YES\n" );
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}