#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void test()
{
    ll n=0;ll k=0;ll k1=0;ll ans=0;
    cin>>n>>k;
    //cout<<n<<' '<<k<<"\n";
    k1=k;
    // if(n%2==1){
    //     if(k%2==1) k1--;
    // }else {
    //     if(k%2==0) k1--;
    // }
    while(n!=0){
        if(n%2==1){
            if(k1%2==0) k1--;
            while(k1>n){
                k1=k1-2;
                cout<<1<<"\n";
            }
            //if(k1%2==1) k1--;
            
        }else if(n%2==0){
            if(k1%2==1) k1--;
            while(k1>n){
                k1=k1-2;;
            }
        }
        n=n-k1;
        ans++;
        //k1=k;
        //cout<<n<<' '<<k1<<"\n";
    }
    //cout<<"n="<<n<<"\n";
    cout<<ans<<"\n";
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    int t=1;
    cin>>t;
    while(t--) test();
    return 0;
}