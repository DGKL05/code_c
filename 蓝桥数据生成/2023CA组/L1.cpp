#include <bits/stdc++.h>
using ll =long long;
using namespace std;
const ll num=1e8;
int main()
{
  // 请在此输入您的代码
  ll ans=0;
  for(int i=10;i<=num;i++){
    string s1=to_string(i);
    if(s1.size()%2==0){
      ll n1=0;ll n2=0;
      ll n3=s1.size();
      for(int j=0;j<n3;j++){
        if(j<(n3/2)) n1+=(s1[j]-'0');
        if(j>=(n3/2)) n2+=(s1[j]-'0');
        // cout<<(s1[j]+'0')<<' ';
      }
      if(n1==n2) ans++;
    }
  }
  cout<<ans<<"\n";
  return 0;
}