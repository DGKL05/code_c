#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    string s1;
    cin>>s1;
    map<char,int>m1;
    for(char x:s1){
        m1[x]++;
    }
    for(auto [l,r]:m1){
        if(r==1){
            cout<<l<<"\n";
            return ;
        }
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