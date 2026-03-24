#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n = 0;
    cin>>n;
    vector<int>v1(n,0);
    for(auto &x:v1) cin>>x;
    int ans=0;
    for(int i=n-1;i>0;i--){
        for(int j=i-1;j>=0;j--){
            if(v1[j] > v1[i]){
                ans++;
                break;
            }
        }
    }
    cout<<ans<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}