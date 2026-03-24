#include <bits/stdc++.h>
using namespace std;
using ll =long long ;
const ll n1=1e7;
int main()
{
  // 请在此输入您的代码
  int num=0;
  for(int i=1;;i++){
    num+=i;
    //cout<<num<<' ';
    if(num>=(n1-1)) {
        cout<<num<<"\n";
        break;
    }
  }
  return 0;
}