#include <iostream>
using namespace std;
int main()
{
  // 请在此输入您的代码
  int T;
  long long n;
  cin>>T;
  for(int i=0;i<T;i++)
  {
      cin>>n;
      if(n%3==0)
      {
        cout<<2*n<<endl;
      }
      else
      {
       cout<<n<<endl;
      }
      
  }
  return 0;
}