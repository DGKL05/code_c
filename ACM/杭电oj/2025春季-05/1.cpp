#include <bits/stdc++.h>
using namespace std;
using ll =long long;

int main()
{
    // 请在此输入您的代码
    string s1;
    for(int i=1;i<=2023;i++){
        s1+=to_string(i);
    }
    //cout<<s1.size()<<"\n";
    ll ans=0;
    ll n=s1.size();
    vector<ll>v3(n);
    ll num1=0;
    for(int i=0;i<n;i++){
        int num=s1[i]-'0';
        //if(num==3) num1++;
        //cout<<num<<" ";
        if(num==3) v3[i]=1;
    }
    //cout<<"num1 = "<<num1<<"\n";
    for(int i=1;i<n;i++){
        v3[i]+=v3[i-1];
    }
    for(int i=0;i<n;i++){
        if(s1[i]=='2'){
            ll num=0;
            for(int j=i+1;j<n;j++){
                if(s1[j]=='0') num++;
                if(s1[j]=='2') {
                    ans+=(num*(v3[n-1]-v3[j]));
                    //cout<<ans<<"\n";
                }
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}