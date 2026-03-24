#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    vector<string>arr(n);
    for(auto &x:arr){
        cin>>x;
    }
    string y;int x=0;
    cin>>x>>y;
    if(arr[--x]==y){
        cout<<"Yes\n";
    }else cout<<"No\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}