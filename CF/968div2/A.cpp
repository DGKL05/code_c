#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const int l =1e7;
void test()
{
    int x=0;int y=0;
    int k=0;
    cin>>x>>y>>k;
    if(k%2==1){
        cout<<x<<' '<<y<<"\n";
        for(int i=1;i<=k/2;i++){
            cout<<x+i<<' '<<y+i<<"\n"<<x-i<<' '<<y-i<<"\n";
        }
    }else {
        for(int i=1;i<=k/2;i++){
            cout<<x+i<<' '<<y+i<<"\n"<<x-i<<' '<<y-i<<"\n";
        }

    }
}

int main()
{
    int t=1;
    cin>>t;
    while(t--) test();
    return 0;
}