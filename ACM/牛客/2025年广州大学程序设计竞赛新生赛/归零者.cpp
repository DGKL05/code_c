#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    string s1;
    cin>>s1;
    s1+="0";
    int ans=0;
    for(int i=0;i<n;i++){
        if(s1[i] == '1'){
            ans++;
            s1[i] = '0';
            s1[i+1] = '0';
        }
    }
    cout<<ans<<'\n';
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