#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int x=0;int y=0;
    cin>>x>>y;
    if(x < 0 ){
        if(y < 0){
            cout<<"0 0\n-_-\n";
        }else {
            cout<<y<<" ";
            if(abs(x) > y) cout<<"0\n";
            else cout<<y - abs(x)<<"\n";
            cout<<"T_T\n";
        }
    }else {
        if(y > 0){
            cout<<max(x , y)<<" "<<x+y<<"\n";
            cout<<"^_^\n";
        }else {
            cout<<x<<" ";
            if(abs(y) > x) cout<<"0\n";
            else cout<<x - abs(y)<<"\n";
            cout<<"T_T\n";
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}