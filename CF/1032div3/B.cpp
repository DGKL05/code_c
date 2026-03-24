#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    string s1;
    cin>>s1;
    set<char>s;
    s.insert(s1[0]);
    s.insert(s1[n-1]);
    for(int i=1;i<n-1;i++){
        if(s.find(s1[i])!=s.end()){
            cout<<"Yes\n";
            return  ;
        }
        s.insert(s1[i]);
    }
    cout<<"No\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}