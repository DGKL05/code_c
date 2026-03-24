#include<bits/stdc++.h>
using namespace std;
using ll =long long;

int check(ll x,ll y){
    return x-y;
}

void test()
{
    int n=0;int m=0;
    cin>>n>>m;
    vector<ll>a(n) , b(m);
    ll aa=0;ll bb=0;
    for(auto &x:a) cin>>x , aa+=x;
    for(auto &x:b) cin>>x , bb+=x;
    int ans = 0;
    sort(a.begin() , a.end());
    sort(b.begin() , b.end());
    ll temp = aa;
    // int ans1=0;
    if(aa == bb){
        cout<<"1\n";
        return ;
    }
    if(aa > bb){
        // int ans
        for(int i=n-1;i>=0;i--){
            temp -= a[i];
            ans++;
            if(temp<=bb){
                cout<<ans<<"\n";
                return ;
            }
        }
    }
    for(int i=m-1;i>=0;i--){
        bb-=b[i];
        ans++;
        if(bb<=aa){
            cout<<ans<<"\n";
            return ;
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}