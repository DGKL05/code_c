#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    vector<int>v1(n-1);
    for(int i=0;i<n-1;i++) cin>>v1[i];
    vector<int>sum(n-1);
    sum[0]=v1[0];
    for(int i=1;i<n-1;i++){
        sum[i]+=sum[i-1]+v1[i];
    }
    for (int x:sum) cout<<x<<" ";
    cout<<"\n";
    for(int i=1;i<n-1;i++){
        for(int j=i;j<n-1;j++){
            cout<<sum[j]-sum[i-1]<<" ";
        }
        cout<<"\n";
    }
    
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}
