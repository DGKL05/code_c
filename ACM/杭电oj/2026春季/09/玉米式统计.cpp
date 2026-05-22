#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    int a=0;int c=0;int b=0;
    int a1=0;int c1=0;int b1=0;
    int a2=0;int c2=0;int b2=0;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        if(a != 0) a1++;
        if(b != 0) b1++;
        if(a && b) c1++;
        if(c) {
            if(a) a2++;
            if(b) b2++;
            if(a && b) c2++;
        }
    }
    //保留两位小数
    float ans = 0.00;
    ans = max(ans, (float)a2/a1);
    ans = max(ans, (float)b2/b1);
    ans = max(ans, (float)c2/c1);
    cout<<fixed<<setprecision(2)<<ans*100<<"%\n";
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