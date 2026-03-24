#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int k=0;
    cin>>n>>k;
    int ans1=0;
    for(int i=1;i<=n;i++){
        int ans=0;
        int num=i;
        while(num){
            ans+=num%10;
            num/=10;
        }
        if(ans == k) {
            ans1++;
        }
    }
    cout<<ans1<<"\n";
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
