#include<bits/stdc++.h>
using namespace std;
using ll =long long;

bool check(int a,int b){
    if(a <= 0 && b<= 0) return true;
    if(a >= 0 && b >= 0) return true;
    return false;
}

void test()
{
    int n=0;int s=0;int x=0;
    cin>>n>>s>>x;
    ll ans = 0;
    for(int i=0;i<n;i++){
        int num =0 ;
        cin>>num;
        ans+=num;
    }
    cout<<(((s-ans) % x == 0 && check(s - ans, x)) ? "YES\n" : "NO\n");
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
