#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    int x=0;
    cin>>x;
    vector<int>v1(n+1);
    for(int i=1;i<=n;i++){
        cin>>v1[i];
    }
    int a=-1;int b=-1;
    for(int i=1;i<=n;i++){
        if(v1[i]==1){
            a=i;
            break;
        }
    }
    for(int i=n;i>=1;i--){
        if(v1[i]==1){
            b=i;
            break;
        }
    }
    if(b==-1 || a==b){
        cout<<"Yes\n";
    }else {
        if(b-a>=x){
            cout<<"No\n";
        }else{
            cout<<"Yes\n";
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}