#include <iostream>
using namespace std;
int dx[8]={0,1,1,1,0,-1,-1,-1};
int dy[8]={1,1,0,-1,-1,-1,0,1};
const int N = 105;
int arr[N][N];
int main()
{
  // 请在此输入您的代码
  int n,m;
  cin>>n>>m;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin>>arr[i][j];
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(arr[i][j]==1) {
        arr[i][j]=9;
      }
      else {
        int ans=0;
        for(int k=0;k<8;k++){
          int x=i+dx[k];int y=j+dy[k];  
          //if(x>n||x<=0||y>m||y<=0) continue;
          if(arr[x][y]==1||arr[x][y]==9) ans++;
        }
        if(ans==1) arr[i][j]=11;
        else arr[i][j]=ans;
      }
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(arr[i][j]!=11) cout<<arr[i][j]<<' ';
      else cout<<"1 ";
    }
    cout<<"\n";
  }
  return 0;
}