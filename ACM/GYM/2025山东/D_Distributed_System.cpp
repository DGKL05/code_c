#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int q=0;
    cin>>n>>q;
    vector<ll>v1(n+10,0);
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        ll num1=a/(n);
        v1[0]+=num1;
        ll st=(b)%(n);
        // if(st==0) st=1;
        ll en=(st+a%n-1)%(n);
        // if(en==0) en=1;
        if(st<=en && n!=1){
            v1[st]++;
            v1[en+1]--;
        }else if(en+1<st){
            v1[0]++;
            v1[en+1]--;
            v1[st]++;
            v1[n]--;
        }
        // cout<<num1<<' '<<st<<" -> "<<en<<"\n";
    }
    for(int i=1;i<n;i++) v1[i]=v1[i-1]+v1[i];
    for(int i=0;i<n;i++)  cout<<v1[i]<<" ";
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