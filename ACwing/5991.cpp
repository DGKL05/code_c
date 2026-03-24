#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    //cout<<__gcd(3,2)<<"\n";
    int n;cin>>n;
    vector<vector<ll>>arr(n+1,vector<ll>(n+1));
    vector<vector<ll>>dp(n+1,vector<ll>(n+1,1e7));
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=n;++j){
            cin>>arr[i][j];
        	if(arr[i][j]!=0)dp[i][j]=arr[i][j];
        }
    }
    vector<int>q(n+1);
    for(int i = 1;i<=n;++i){
        if(arr[1][i]!=0)q[i]=1;
    	else q[i]=i;
    }
    for(int i = 1;i<=n;++i)dp[i][i]=0;
    for(int k = 1;k<=n;++k){
        for(int i = 1;i<=n;++i){
            for(int j = i+1;j<=n;++j){
                //if(i==j||i==k||j==k)continue;
                if(dp[i][j]>dp[i][k]+dp[k][j]){
                    dp[i][j]=dp[i][k]+dp[k][j];
                    if(i==1&&arr[k][j]!=0)q[j]=k;
                    //if(k==j)q[j]=i;
                    //cout<<i<<' '<<k<<' '<<j<<' '<<dp[i][j]<<endl;
                }
            }
        }
    }
    //cout<<q[3];
    cout<<"minlong="<<dp[1][n]<<endl;
    //if(n==1)return 0;
    stack<int>s;
    int z = n;
    while(q[z]!=z){
        s.push(z);z=q[z];
    }
    cout<<1;
    while(!s.empty()){
        cout<<' '<<s.top();s.pop();
    }
}