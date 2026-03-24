#include<bits/stdc++.h>
using namespace std;
using ll =long long;

set<ll>s1;
set<ll>s2;
void test()
{
    int n=0;
    cin>>n;
    int n1=n/2;
    vector<int>v1(n1,0);
    s1.clear();
    int idx=0;
    ll num=1;
    for(int i=0;i<n/2;i++){
        while(s1.find(num)!=s1.end() || s2.find(num)!=s2.end()){
            num++;
        }
        // cout<<num<<" ";
        v1[idx]=num;
        idx++;
        
        for(auto x:v1){
            s1.insert(x*num);
        }
        num++;
    }
    // cout<<"\n";
    for(int i=0;i<n1;i++) cout<<v1[i]<<" ";
    cout<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    for(int i=1;i<=1e6;i++){
        s2.insert(pow(i,2));
        // cout<<pow(i,2)<<"\n";
    }
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}