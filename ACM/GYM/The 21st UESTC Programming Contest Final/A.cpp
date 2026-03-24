#include<bits/stdc++.h>
using namespace std;
using ll =long long;

class MyCompare {
    public:
    bool operator() (double a, double b) const {
        return a < b; // 降序排列
    }
};

void test()
{
    int n=0;
    cin>>n;
    vector<string>v1(n);
    for(int i=0;i<n;i++){
        cin>>v1[i];
    }
    multimap<double,int,MyCompare>m1;
    for(int i=0;i<n;i++){
        // cout<<v1[i]<<"\n";
        bool fa=true;int ans=0;
        for(char x:v1[i]){
            if(x=='1') {
                fa=false;
                ans++;
            }
        }
        // cout<<ans<<' '<<v1[i].size()<<"\n";
        if(ans!=0&&ans!=v1[i].size()) m1.insert(pair<double,int>((double)ans/v1[i].size(),i));
    }
    vector<string>v2;
    auto it=m1.begin();
    while(it!=m1.end()){
        // cout<<it->first<<" ";
        v2.push_back(v1[it->second]);
        // cout<<v1[it->second]<<"\n";
        it++;
    }
    // cout<<v2.size()<<"\n";
    ll ans=0;ll num=0;
    for(int i=0;i<v2.size();i++){
        // cout<<v2[i]<<" ";
        for(char x:v2[i]){
            if(x=='0'){
                ans+=num;
            }else{
                num++;
            }
        }
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test();
    return 0;
}