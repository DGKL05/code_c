#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    if(n%2==1){
        for(int i=1;i<=n;i++){
            cout<<i<<" ";
        }
        cout<<"\n";
        return ;
    }
    for(int i=1;i<=n;i++){
        if(i%2==1){
            cout<<i+1<<" ";
        }else cout<<i-1<<" ";
    }
    cout<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}