#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    ll s=0;
    cin>>s;
    ll s1=s;
    for(int i=0;i<n;i++){
        int y=0;
        cin>>y;
        if((s1+y+1)/2 >s1){
            s1=(s1+y+1)/2;
        }else {
            s=(s+y+1)/2;
        }
    }
    cout<<max(s,s1)<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}
