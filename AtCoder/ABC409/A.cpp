#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    for(int i=0;i<n;i++){
        if(s1[i]=='o' && s2[i]=='o'){
            cout<<"Yes\n";
            return ;
        }
    }
    cout<<"No\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}