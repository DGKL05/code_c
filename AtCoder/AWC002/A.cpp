#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;ll k=0;
    cin>>n>>k;
    int ans=-1;
    for(int i=1;i<=n;i++){
        int num = 0;
        cin>>num;
        if(num == k && ans == -1){
            ans = i;
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