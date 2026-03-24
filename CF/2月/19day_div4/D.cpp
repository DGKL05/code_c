#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int m=0;
    cin>>n>>m;
    //cout<<n*m<<"\n";
    ll ans=0;ll num=0;
    vector<vector<int>>v1(n,vector<int>(m));
    vector<int>pai(n);
    for(int i=0;i<n;i++){
        pai[i]=i;
        for(int j=0;j<m;j++){
            cin>>v1[i][j];
        }
    }
    vector<bool>fa(n,false);
    int shu=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            shu=i*m;
            ll val_i=0;
            ll val_j=0;
            for(int x=0;x<m;x++){
                val_i+=(v1[i][x]*(n*m-shu));
                val_j+=(v1[j][x]*(n*m-shu));
                //cout<<"n*m-shu="<<n*m-shu<<"\n";
                shu++;
            }
            if(val_i<=val_j){
                //cout<<"i="<<val_i<<" j="<<val_j<<"\n";
                swap(v1[i],v1[j]);
            }
        }
    }
    shu=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            //cout<<v1[i][j]<<' ';
            num+=v1[i][j]*(n*m-shu);
            shu++;
        }
    }
    //cout<<"\n";
    cout<<num<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int t=0;
    cin>>t;
    while(t--){
        test();
    }
}