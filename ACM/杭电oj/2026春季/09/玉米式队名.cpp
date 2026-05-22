#include<bits/stdc++.h>
using namespace std;
using ll =long long;

const string ans = "execute";

void test()
{
    string s1;
    cin>>s1;
    int n = s1.size();
    for(int i=n-1;(i - 6)>=0;i--){
        // cout<<s1.substr(i-6, 7)<<"\n";
        if(s1.substr(i-6, 7) == ans){
            s1[i-6] = '1';
        }
    }
    cout<<s1<<"\n";
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