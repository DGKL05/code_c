#include<bits/stdc++.h>
using namespace std;
using ll =long long;
vector<int>be;
vector<vector<int>>index_e;
vector<int>dp;
int main()
{
    std::ios_base::sync_with_stdio(false);
    int n=0;
    cin>>n;
    be.resize(n);
    index_e.resize(10);
    for(int i=0;i<n;i++){
        string s1;
        cin>>s1;
        be[i]=s1[0]-'0';
        index_e[s1[(s1.size()-1)]-'0'].push_back(i);
    }
    dp.resize(n);
    dp[0]=1;
    for(int i=1;i<n;i++){
      dp[i]=1;
        for(int j:index_e[be[i]]){
            if(j>=i) break;
            //cout<<j<<" ";
            dp[i]=max(dp[j]+1,dp[i]);
        }
        //cout<<"\n";
    }
    int num=0;
    for(int x:dp){
        //cout<<x<<' ';
        num=max(num,x);
    }
    cout<<n-num<<"\n";
    return 0;
}