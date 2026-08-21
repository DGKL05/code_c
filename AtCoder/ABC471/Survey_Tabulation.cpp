#include<bits/stdc++.h>

using namespace std;
using ll = long long;

string ins(string &s1){
    for(auto &x : s1){
        if(x>=97 && x<=122){
            x -= 32;
        }
    }
    return s1;
}

void test(){
    int n=0;
    cin>>n;
    string s1;
    map<string,int>m1;
    for(int i=0;i<n;i++){
        cin>>s1;
        s1 = ins(s1);
        m1[s1] ++;
    }
    int ans = 0;
    string s2;
    for(auto [l,r] : m1){
        if(r > ans) {
            ans= r;
            s2 = l;
        }
    }
    cout<<ans<<"\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin>>T;
    while(T--) test();
    return 0;
}