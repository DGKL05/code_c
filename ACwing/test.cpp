#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=25;
int arr[N][N];
int dp[N][N];
const int MAX=1e7;
int pre[N];
int main(){
    int n=0;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            cin>>arr[i][j];
            if(arr[i][j]!=0) dp[i][j] = arr[i][j];
            else dp[i][j]=MAX;
        }
    for(int i=1;i<=n;i++) dp[i][i]=0;
    vector<int>q(n+1);
    for(int i = 1;i<=n;++i){
        if(arr[1][i]!=0)q[i]=1;
    	else q[i]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(j==i+1) {
                if(arr[i][j]!=0) {
                    dp[i][j]=arr[i][j];
                }
            }else {
                for(int k=i+1;k<j;k++){
                    if(dp[i][j]>(dp[i][k]+dp[k][j])){
                        dp[i][j]=dp[i][k]+dp[k][j];
                        if(i==1&&arr[k][j]!=0)q[j]=k;
                    }
                }
            }
        }
    }
    cout<<"minlong="<<dp[1][n]<<endl;
    stack<int>s;
    int z = n;
    while(q[z]!=z){
        s.push(z);z=q[z];
    }
    cout<<1;
    while(!s.empty()){
        cout<<' '<<s.top();s.pop();
    }
    return 0;
}