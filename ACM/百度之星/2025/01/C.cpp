#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const int N =2*1e6+10;
ll m1[N];
void test()
{
    int n=0;
    cin>>n;
    for(int i=0;i<=n;i++){
        m1[i]=0;
    }
    int num=0;
    for(int i=0;i<n;i++){
        cin>>num;
        m1[num]++;
    }
    for(int i=0;i<=n;i++){
        ll r=m1[i];
        if(r%2==0 && r!=0){
            cout<<"No\n";
            return ;
        }
    }
    cout<<"Yes\n";
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