#include<bits/stdc++.h>
using namespace std;
using ll =long long;
#define int long long

void test()
{
    int n=0;
    cin>>n;
    string s1;
    cin>>s1;
    int k=0;
    for(int i=0;i<n;i++){
        if(s1[i] == '1') k++;
    }
    if(k == n || k == 0) {
        cout<<"0\n";
        return ;
    }
    int temp=0;int num=0;

    for(int i=0;i<n;i++){
        if(s1[i] == '1') temp++;
        else {
            num=max(temp,num);
            temp=0;
        }
    }
    num=max(temp,num);
    int tempa=0;int numa=0;

    for(int i=0;i<n;i++){
        if(s1[i] == '0') tempa++;
        else {
            numa=max(tempa,numa);
            tempa=0;
        }
    }
    numa=max(tempa,numa);
    ll ans=1LL*(k-num)*2 + (n-k);
    int k1=n-k;
    ll ans1=1LL*(k1-numa)*2+k;
    cout<<min({2*n,ans,ans1})<<"\n";
}

signed main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}