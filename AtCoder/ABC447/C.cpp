#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void test()
{
    string s;string t;
    cin>>s>>t;
    int sz=s.size();
    int tz=t.size();
    int idx=0;
    int ans=0;
    string s1;string t1;
    for(auto x:s){
        if(x!='A') s1+=x;
    }
    for(auto x:t){
        if(x!='A') t1+=x;
    }
    if(s1 != t1){
        cout<<"-1\n";
        return ;
    }
    for(int i=0;i<tz;){
        if(s[idx] == t[i]) {
            // cout<<t[i]<<" ";
            i++;
            idx++;
            continue;
        }
        if(t[i] != 'A'){
            if(s[idx] != 'A'){
                cout<<"-1\n";
                return ;
            }else {
                idx++;
                ans++;
            }
        }else {
            ans++;
            // idx++;
            i++;
        }
    }
    while(idx<sz){
        if(s[idx] != 'A'){
            cout<<"-1\n";
            return ;
        }
        idx++;
        ans++;
    }
    cout<<ans<<"\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T=1;
    // cin>>T;
    while(T--) test();
}