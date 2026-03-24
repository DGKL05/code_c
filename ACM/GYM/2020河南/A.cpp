#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const int N=100;
vector<pair<int,int>>v1(N);
void test()
{
    int n=0;int m=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int c=0;int t=0;
        cin>>c>>t;
        if(t>v1[c].first){
            v1[c]={t,i+1};
        }
    }
    for(int i=1;i<=m;i++){
        cout<<v1[i].second<<' ';
    }
}

int main()
{
    int T=1;
    // cin>>T;
    while(T--) test();
    return 0;
}