#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    string s1;
    cin>>s1;
    int idx=-1;
    int n=s1.size();
    if(s1[0]!='>' || (s1[n-1]!='>' || s1[n-2]!='>' || s1[n-3]!='>')){
        cout<<"No\n";
        return ;
    }
    for(int i=n-1;i>=0;i--){
        if(s1[i] == '>'){
            idx = i;
            break;
        }
    }
    if(idx == -1){
        cout<<"No\n";
        return ;
    }
    int idx_si = 0;int st = -1;
    for(int i=idx;i>=0;i--){
        if(s1[i] == '>'){
            st = i;
            idx_si++;
        }else break;
    }
    if(idx_si<3 || idx_si == n || st==-1){
        cout<<"No\n";
        return ;
    }
    int num = idx_si/3;
    // cout<<num<<"\n";
    // if(idx_si%3!=0) num++;
    int bianjie=-1;
    for(int i=st-1;i>=0;i--){
        if(s1[i] == '>') {
            bianjie = i;
            break;
        }
    }
    vector<pair<int,int>>ans;
    for(int i=0;i<bianjie;i++){
        if(s1[i] == '>'){
            ans.push_back({i,idx-i+1});
        }
    }
    int k=0;
    for(int i=0;i<num;i++){
        ans.push_back({bianjie,idx-bianjie+1-3*(k++)});
    }
    // cout<<st<<"\n";
    if(idx_si%3!=0) {
        ans.push_back({bianjie,st-bianjie+1+2});
    }
    cout<<"Yes "<<ans.size()<<"\n";
    for(auto [l,r] : ans){
        cout<<l+1<<" "<<r<<"\n";
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