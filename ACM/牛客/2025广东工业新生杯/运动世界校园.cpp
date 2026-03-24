#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    double p = 0.0;
    cin>>p;
    double ans = 0.0;
    for(int i=1;i<=3;i++){
        ans+=(1LL*pow((1-p),i-1)*p);
    }
    printf("%.4lf",ans);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}