#include<bits/stdc++.h>
using namespace std;
using ll =long long;


void test()
{
    int n=0;int k = 0;int num=0;int ans=0;
    cin>>n>>k>>num;
    vector<int>arr(291);
    vector<bool>fa(291 , false);
    for(int i=0;i<n;i++){
        int a=0;int b=0;
        cin>>a>>b;
        if(a < 175) continue;
        if(b >= num) ans++;
        else if(arr[a] < k) {
            arr[a]++;
            ans++;
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
    // cin>>T;
    while(T--) test(); 
    return 0;
}