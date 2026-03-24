#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int a=0;int b=0;
    cin>>n>>a>>b;
    string s1;
    cin>>s1;
    for(int i=a;i<n-b;i++){
        cout<<s1[i];
    }
    cout<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}