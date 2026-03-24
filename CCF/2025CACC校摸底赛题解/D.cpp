#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int k=0;
    cin>>n>>k;
    vector<int>sum(10005,0);
    for(int i=0;i<n;i++){
        int num=0;
        cin>>num;
        sum[num]++;
    }
    for(int i=1;i<=10000;i++){
        sum[i]+=sum[i-1];
    }
    int ans=0;
    for(int i=1;i<=10000;i++){
        if((i+k)<=10000){
            ans = max(ans , sum[i+k] - sum[i-1]);
        }
    }
    cout<<ans<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}