#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int s=0;int t=0;
    cin>>n>>s>>t;
    vector<int>v1(2*n+2);
    for(int i=0;i<n;i++){
        cin>>v1[i+1];
        v1[v1[i+1]]=i+1;
    }
    if(s == t){
        cout<<"Yes\n";
        return ;
    }
    if(n==2){
        if(s<=2 && t<=2 ){
            cout<<"No\n";
            return ;
        }
        if(s>=3 && t>=3 ){
            cout<<"No\n";
            return ;
        }
        if(v1[s] == t || v1[t] == s){
            cout<<"No\n";
            return ;
        }
        cout<<"Yes\n";
        return ;
    }
    if(v1[s] == t || v1[t] == s){
        cout<<"No\n";
        return ;
    }
    cout<<'Yes\n';
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}