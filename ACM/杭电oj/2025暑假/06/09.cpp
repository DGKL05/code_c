#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    vector<ll>v1(n);
    int idx=-1;ll max_num=-1;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        v1[i]=x;
        if(x>max_num){
            max_num=x;
            idx=i;
        }
    }
    if(n<=2){
        cout<<"0\n";
        return ;
    }
    if(idx!=(n-1)){
        cout<<1LL*max_num*(n-3)+max(v1[0],v1[n-1])<<"\n";
    }else cout<<1LL*max_num*(n-2)<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}