#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int x,y;
    cin>>x>>y;
    int ans=0;
    for(int i=1;i<7;i++){
        for(int j=1;j<7;j++){
            if((i+j)>=x) ans++;
            else if(abs(i-j)>=y) ans++;
        }
    }
    printf("%.10lf",(double)ans/36);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}