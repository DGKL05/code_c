#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int k=0;
    cin>>n>>k;
    int temp=0;
    bool fa=false;
    string v1;
    cin>>v1;
    for(int i=0;i<n;i++){
        if(v1[i]=='1'){
            temp++;
            if(temp==k){
                cout<<"NO\n";
                return ;
            }
        }else temp=0;
    }
    cout<<"YES\n";
    int num=1;temp=n;
    for(int i=0;i<n;i++){
        if(v1[i]=='1'){
            cout<<num++<<" ";
        }else cout<<temp--<<" ";
    }
    cout<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}