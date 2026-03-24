#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int a,b,x,y,p;
    cin>>a>>b>>x>>y>>p;
    set<int>s1;
    int temp=p;
    for(int i=0;i<=p/x;i++){
        temp=temp-i*x;
        for(int j=0;j<=temp/y;j++){
            temp=temp-j*y;
            s1.insert((a+i)*(b+j));
            temp=temp+j*y;
        }
        temp=temp+i*x;
    }
    cout<<s1.size()<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}
