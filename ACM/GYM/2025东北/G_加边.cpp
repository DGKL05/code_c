#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int m=0;
    cin>>n>>m;
    map<int,int>m1;
    vector<int>v1;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        m1[a]++;
        m1[b]++;
    }
    for(auto [l,r]:m1){
        int r1=r;
        if((int)r1%2==1) v1.push_back(l);
    }
    cout<<v1.size()/2<<'\n';
    for(int i=0;i<v1.size();i+=2){
        cout<<v1[i]<<' '<<v1[i+1]<<"\n";
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}