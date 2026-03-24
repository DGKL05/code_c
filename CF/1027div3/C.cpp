#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    vector<int>v1(n);
    for(int i=0;i<n;i++){
        cin>>v1[i];
    }
    int ans=1;int index=0;
    for(int i=1;i<n;i++){
        if(v1[index]+1<v1[i]){
            ans++;
            index=i;
        }
    }
    cout<<ans<<'\n';
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}