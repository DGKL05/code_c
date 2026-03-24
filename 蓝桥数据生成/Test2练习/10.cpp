#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
const int N = 3e6+5;
ll arr[N];
vector<int>v;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    for(int i=0;i<N;i++) arr[i]=1;
    for(int i=2;i<N;i++){
        int num=2;
        while(num*i<=N){
            arr[(num*i)]=0;
            num++;
        }
        if(arr[i]==1){
            arr[i]=i;
            v.push_back(i);
        }else {
            for(int j:v){
                if(i%j==0) {
                    arr[i]=j;
                    break;
                }
            }
        }
    }
    arr[1]=0;arr[2]=2;arr[1]=0;
    for(int i=2;i<=N;i++) arr[i]=arr[i-1]+arr[i];
    int t=0;
    cin>>t;
    while(t--){
        int x=0;
        cin>>x;
        cout<<arr[x]<<"\n";
    }
    return 0;
}