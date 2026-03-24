#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const int N=3*1e5+10;
ll v1[N]={0};
void test()
{
    int n=0;int l=0;
    cin>>n>>l;
    int a=l/3;
    v1[1]++;
    int idx=1;
    for(int i=1;i<n;i++){
        int b;
        cin>>b;
        v1[(idx+b)%l]++;
        idx=(idx+b)%l;
    }
    if(l%3!=0){
        cout<<"0\n";
        return ;
    }
    ll ans=0;
    for(int i=1;i<l;i++){
        if(v1[i]!=0 && v1[(i+a)%l]!=0 && v1[((i+a)%l+a)%l]!=0){
            ans+=1LL*(v1[i]*v1[(i+a)%l]*v1[((i+a)%l+a)%l]);
            v1[i]=0;
            v1[(i+a)%l]=0;
            v1[((i+a)%l+a)%l]=0;
        }
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