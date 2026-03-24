#include<bits/stdc++.h>
using namespace std;
using ll =long long;

string s1="Gellyfish";
string s2="Flower";
void test()
{
    ll a1=0;ll a2=0;ll b1=0;ll b2=0;
    cin>>a1>>b1>>a2>>b2;
    if(a2>=b2){
        if(a1>=b2){
            cout << s1 <<"\n";
        }else {
            if(a1<b1) cout<<s2<<"\n";
            else cout<<s1<<"\n";
        }
    }else {
        if(b1<=a2){
            if(a1>=b1) cout<<s1<<"\n";
            else cout<<s2<<'\n';
        }else {
            cout<<s2<<"\n";
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}