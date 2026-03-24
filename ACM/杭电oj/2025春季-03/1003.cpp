#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int m=0;
    cin>>n>>m;
    vector<ll>v1(m);
    for(int i=0;i<m;i++){
        cin>>v1[i];
    }
    vector<vector<pair<ll,ll>>>v2;
    v2.resize(m);
    for(int i=0;i<m;i++){
        v2[i].resize(n);
    }
    for(int i=0;i<n;i++){
        vector<ll>v3(m);
        for(int j=0;j<m;j++){
            cin>>v3[j];
        }
        for(int j=0;j<m;j++){
            ll num=0;
            cin>>num;
            v2[j][i]={v3[j],num};
           //cout<<v2[j][i].first<<' '<<v2[j][i].second<<"\n";
        }
    }
    for(int i=0;i<m;i++){
        sort(v2[i].begin(),v2[i].end());
    }
    //sort(v2.begin(),v2.end());
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){  
    //        cout<<v2[j][i].first<<"->"<<v2[j][i].second<<" ";
    //     }
    //     cout<<"\n";
    // }
    for(int i=0;i<n;i++){
        ll num=v1[i];
        for(int j=0;j<m;j++){
            //cout<<v2[i][j].first<<' '<<v2[i][j].second<<"\n";
            if(j==0){
                if(v1[i]<v2[j][i].first){
                    cout<<"NO\n";
                    return ;
                }
            }else{
                if(num<v2[j][i].first){
                    cout<<"NO\n";
                    return ;
                }
            }
            num+=v2[j][i].second;
        }
    }
    cout<<"YES\n";
}

int main()
{
    int t=0;
    cin>>t;
    while(t--) test();
    return 0;
}
