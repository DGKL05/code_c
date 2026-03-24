#include<bits/stdc++.h>
using namespace std;
using ll =long long;
//"Ocelot", "Serval", "Lynx".
void test()
{
    map<string,int>m1;
    m1["Ocelot"]=3;
    m1["Serval"]=2;
    m1["Lynx"]=1;
    string x;string y;
    cin>>x>>y;
    int a=0;int b=0;
    a=m1[x];
    b=m1[y];
    if(b>=a){
        cout<<"Yes\n";
    }else cout<<"No\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}