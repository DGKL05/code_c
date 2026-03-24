#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    int idx_a=-1;int idx_b=-1;
    ll ans1=0;ll ans2=0;
    ll num=0;
    vector<ll>a(n),b(n);
    for(int i=0;i<n;i++) {
        cin>>num,ans1+=num;
        if(num==1) idx_a=i;
        a[i]=num;
    }
    ll ans=0;
    for(int i=0;i<n;i++) {
        cin>>num,ans2+=num;
        if(num==1) idx_b=i;
        b[i] = num;
    }
    if(ans1 != ans2) {
        cout<<"No\n";
        return ;
    }
    if(ans1==1){
        if(a[0]==b[0] && a[n-1]==b[n-1]){
            cout<<"Yes\n";
            return ;
        }
        cout<<"No\n";
        return ;
    }
    cout<<"Yes\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}