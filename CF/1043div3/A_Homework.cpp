#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    string s1;
    cin>>s1;
    int m=0;
    cin>>m;
    string op;
    cin>>op;
    string name;
    cin>>name;
    for(int i=0;i<m;i++){
        if(name[i]=='D'){
            s1=s1+op[i];
        }else {
            s1=op[i]+s1;
        }
    }
    cout<<s1<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}