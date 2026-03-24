#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    ll ans=0;
    string s1;
    cin>>s1;
    ll num1=0;
    int n=s1.size();
    for(int i=n-1;i>=0;i--){
        int a=(s1[i]-'0');
        if(num1==0){
            ans+=a;
            num1+=a; 
        }else{
            int b=num1%10;
            a+=10;
            ans+=(a-b)%10;
            num1+=(a-b)%10;
        }
    }
    cout<<ans+s1.size()<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}