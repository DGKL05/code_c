#include<bits/stdc++.h>
using namespace std;
using ll =long long ;

void test(){
    int n=0;
    int num=0;
    cin>>n;
    int j=1;
    for(int i=n;i>=1;i--){
        num+=abs(i-j);
        j++;
    }
    int k=0;int ans=1;
    while(num!=k){
        k+=2;
        ans++;
    }
    cout<<ans<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int t=0;
    cin>>t;
    while(t--) test();
    return 0;
}