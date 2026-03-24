#include<bits/stdc++.h>
using namespace std;
using ll =long long;


void test()
{
    int ans=0;
    vector<int>val(26);
    for(int i=0;i<26;i++){
        cin>>val[i];
    }
    string s1;
    cin>>s1;
    for(char c : s1){
        if(val[c - 'a']!=0) ans++;
        // cout<<c<<' '<<(int)c-'a'<<"\n";
    }
    if(ans!=0) cout<<ans<<"\n";
    else cout<<s1.size()<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}
