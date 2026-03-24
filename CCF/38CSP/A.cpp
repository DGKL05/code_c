#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int x=0;int y=0;int n=0;
    cin>>x>>y>>n;
    double a=10.0*(n-x)/y+1;
    string s1=to_string(a);
    bool fa=false;
    int y1=1;
    for(int i=0;i<s1.size();i++){
        if(s1[i]=='.'){
            y1=(s1[++i]-'0')+1;
            break;
        }
    }
    cout<<(int)a<<" "<<y1<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}