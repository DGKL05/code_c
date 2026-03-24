#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MAXK=500000;
const ll mod=998244353;
const ll inv2=(mod+1)/2;
const ll inv4=(1LL*inv2*inv2)%mod;
ll pow2[MAXK+1];
void f(){
    pow2[0]=1;
    for(int i=1;i<=MAXK;i++){
        pow2[i]=(pow2[i-1]*2)%mod;
    }
}
void test(){
    int n;
    cin>>n;
    vector<int>arr(n);
    int k=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]==-1){
            k++;
        }
    }
    ll num=pow2[k];
    ll ans=0;
    if(arr[0]==1){
        ans=(ans+num)%mod;
    }else if(arr[0]==-1){
        ans=(ans+num*inv2)%mod;
    }
    for(int i=1;i<n;i++){
        if(arr[i-1]!=-1&&arr[i]!=-1){
            if(arr[i-1]==0&&arr[i]==1){
                ans=(ans+num)%mod;
            }
        }else if(arr[i-1]!=-1&&arr[i]==-1){
            if(arr[i-1]==0){
                ans=(ans+num*inv2)%mod;
            }
        }else if(arr[i-1]==-1&&arr[i]!=-1){
            if(arr[i]==1){
                ans=(ans+num*inv2)%mod;
            }
        }else{
            ans=(ans+num*inv4)%mod;
        }
    }
    cout<<ans<<'\n';
}
int main(){
    std::ios_base::sync_with_stdio(false);
    f();
    int T=1;
    cin>>T;
    while(T--)test();
    return 0;
}