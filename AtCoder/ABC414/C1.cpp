#include<bits/stdc++.h>
using namespace std;
using ll =unsigned long long;
int a=0;string n;ll ans;
string s1;
void intToA(string &sk,int radix)
{
    ll n2 = stoll(sk);
    string str_ans="";
    do{
        ll t=n2%radix;
        if(t>=0&&t<=9) str_ans+=(t+'0');
        else str_ans+=(t-10+'a');
        n2/=radix;
    }while(n2!=0);  
    string temp = str_ans;
    reverse(str_ans.begin(),str_ans.end());
    if(temp == str_ans) ans+=stoll(sk);
    else return ;
    // cout<<sk<<"\n";
}


void test()
{
    cin>>a>>n;
    ll n1=stoll(n);
    for(int i=1;i<=n1;i++){
        string str_ans = to_string(i);
        string temp = str_ans;
        reverse(str_ans.begin(),str_ans.end());
        if(temp == str_ans) intToA(str_ans , a);
    }
    cout<<ans<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}