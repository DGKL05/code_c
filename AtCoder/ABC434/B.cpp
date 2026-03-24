#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int m=0;
    cin>>n>>m;
    vector<double>arr(m+1,0);
    vector<int>cnt(m+1,0);
    int a=0;int b=0;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        arr[a] += b;
        cnt[a] ++;
    }
    for(int i=1;i<=m;i++){
        // cout << arr[i]/cnt[i] <<"\n";
        printf("%0.5lf\n",1.00000*arr[i]/cnt[i]);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}