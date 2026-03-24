#include<bits/stdc++.h>
using namespace std;
const int N = 1e9+5;
bool arr[N]={true};
void test()
{
    int n=0;int k=0;
    cin>>n>>k;
    if(k==1){
        if(arr[n]) cout<<"YES\n";
        else cout<<"NO\n";
    }else{
        cout<<"NO\n";
    }
}

int main()
{
    for(int i=1;i<=N;i++){
        int num=2;
        while(num*i<=N){
            arr[num*i]=false;
            num++;
        }
        if(arr[i]&&i%2==1){
            for(int j=3;j*j<i;j++){
                if(i%j==0) arr[i]=false;
                break;
            }
        }
    }
    int t=0;
    cin>>t;
    while(t--) test();
    return 0;
}