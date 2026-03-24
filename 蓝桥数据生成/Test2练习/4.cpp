#include <bits/stdc++.h>
using namespace std;
const int N =1e3+5;

int a[N];int b[N];
int dp[N][N], len1, len2;
 
void lcs(int i,int j)
{
  // cout<<len1<<' '<<len2<<"\n";
  for(i=1; i<=len1; i++)
  {
    for(j=1; j<=len2; j++){
      if(a[i-1] == b[j-1])
        dp[i][j] = dp[i-1][j-1] + 1;
      else 
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
  }
}
 
int main()
{
    cin>>len1>>len2;
    for(int i=0;i<len1;i++){
      int num=0;
      cin>>num;
      a[i]=num;
    }
    for(int i=0;i<len2;i++){
      int num=0;
      cin>>num;
      b[i]=num;
    }
    memset(dp, 0, sizeof(dp));
    lcs(len1, len2);

    cout<<dp[len1][len2]<<"\n";
    return 0;
}