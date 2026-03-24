#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int num=0;
    cin>>n;
    string s1;
    cin>>s1;
    bool fa=0;
    for(auto x:s1){
        if(x!='0') fa=true;
    }
    if(!fa) {
        cout<<0<<"\n";
        return ;
    }
    for(int i=s1.size()-1;i>=0;i--){
        if(s1[i]!=s1[i-1]){num++;}
    }
    if(s1[0]=='0') num--;
    cout<<num<<"\n";
}

int main()
{
    int t=0;
    cin>>t;
    while(t--){
        test();
    }
}