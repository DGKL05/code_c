#include<bits/stdc++.h>
using namespace std;
using ll =long long ;

void test()
{
    int n=0;int num=0;
    cin>>n;
    vector<int>v1(n);
    for(int i=0;i<n;i++){
        cin>>v1[i];
        num=max(num,v1[i]);
    }
    for(int x=0;x<n;x++){
        if(v1[x]==num){cout<<x+1<<' ';}
    }
    cout<<"\n";
}

int main()
{
    int t=0;
    cin>>t;
    while(t--){
        test();
    }
}