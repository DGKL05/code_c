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
    cout<<n<<"\n";
    int num=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>num;
            if(i>=j) cout<<"0 ";
            else cout<<num<<' ';
        }
        cout<<"\n";
    }
    return 0;
}