#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n = 0;
    cin>>n;
    double ans = 0;
    for(int i = 1;i<=n;++i){
        double a;cin>>a;
        ans += a;
    }
    ans /= (double)(n+1);
    printf("%.6lf ",ans*2);
    for(int i = 2;i<=n;++i){
        printf("%.6lf",ans);
        if(i!=n)printf(" ");
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}