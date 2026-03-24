#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const int N = 1e5+5;
int sum[N];
int index_i[N];
void test()
{
    
}

int main()
{
    //cout<<sqrt(35)<<"\n";
    for(int i=1;i<=N;i++){
        sum[i]=sum[i-1]+i;
        if(pow(sqrt(sum[i]),2)==sum[i]&&i==6){
            index_i[i]=i;
            cout<<pow(sqrt(sum[i]),2)<<" ";
        }
    }
    int t=0;
    cin>>t;
    while(t--) test();
    return 0;
}