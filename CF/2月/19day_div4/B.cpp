#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    string str;
    cin>>str;
    bool fa=false;
    for(int i=0;i<str.size()-1;i++){
        if(str[i]==str[i+1]) fa=true;
    }
    if(fa){
        cout<<1<<"\n";
    }else {
        cout<<str.size()<<"\n";
    }
}

int main()
{
    int t=0;
    cin>>t;
    while(t--){
        test();
    }
}