#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    vector<ll>v1(n);
    for(int i=0;i<n;i++) cin>>v1[i];
    ll k=0;
    if(n>1) k=v1[1]-v1[0];
    bool fa=true;
    for(int i=2;i<n;i++){
        if((v1[i]-v1[i-1])!=k){
            fa=false;
            break;
        }
    }
    if(!fa){
        cout<<"No\n";
        return ;
    }
    ll b = v1[0] - k;

    if (b < 0) {
        cout << "NO\n";
        return ;
    }
    if (b % (n + 1) != 0) {
        cout << "NO\n";
        return ;
    }
    ll y = b / (n + 1);
    ll x = k + y;
    if (x >= 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}