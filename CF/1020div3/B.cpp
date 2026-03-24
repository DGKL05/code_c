#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int x=0;
    cin>>n>>x;
    if(n==1){
        cout<<"0\n";
        return ;
    }
    
    for(int i=0;i<n;i++){
        if(i!=x) cout<<i<<' ';
    }
    if(n!=x) cout<<x;
    cout<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int t=0;
    cin>>t;
    while(t--) test();
    return 0;
}