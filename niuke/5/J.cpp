#include<bits/stdc++.h>
using namespace std;
using ll =long long ;

void test()
{
    ll n=0;string str;ll v=0;ll s1=0;
    cin>>n>>str;
    for(auto s:str){
        if(s=='0'){
            v+=10;
            if(v>=0)s1+=v;
        }
        else if(s=='1'){
            if(v-5>=0){
                v-=5;
            }
            else {
                v=0;
            }
            if(v>=0)s1+=v;
        }
        else if(s=='2'){
            ll temp=v;
            v-=10;
            if(v>=0)s1+=v;
            v=temp;
        }
    }
    cout<<s1<<"\n";
}

int main()
{
    int t=1;
    //cin>>t;
    while(t--){
        test();
    }
}