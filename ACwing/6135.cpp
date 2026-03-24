#include<bits/stdc++.h>
using namespace std;
using ll =long long;

int main()
{
    std::ios_base::sync_with_stdio(false);
    int n=0;int sum1=0;
    cin>>n;
    vector<int>a(n,0);
    vector<int>b(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
        if(a[i]==b[i]) sum1++;
    }
    vector<int>sum(n+1,0);
    vector<vector<int>>dp(n+1,vector<int>(n+1));
    int num=sum1;
    for(int i=0;i<n;i++){
        dp[i][i]=sum1;
        dp[i+1][i]=sum1;
        sum[sum1]++;
    }
    //dp[n]
    for(int len=2;len<=n;len++){
        for(int i=0;i<n-len+1;i++){
            int j=i+len-1;
            dp[i][j]=dp[i+1][j-1]+(a[i]==b[j])+(a[j]==b[i])-(a[i]==b[i])-(a[j]==b[j]);
            sum[dp[i][j]]++;
        }
    }
    for(int x:sum){
        cout<<x<<"\n";
    }
    return 0;
}