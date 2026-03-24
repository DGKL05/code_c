#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    ll a, b;
    cin >> a >> b;
    ll num = (a > b) ? (a - b) : (b - a);
    ll d0 = num * (a + b);
    ll A = (d0 + 1) / 2 - 1;
    ll B = (d0 >= 8) ? (d0 / 4 - 1) : 0;
    cout << A + B << '\n';
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    // set<ll>s1;
    // ll N = 100;
    // for(int i=1;i<=N;i++){
    //     cout<<"i = "<<i<<" : ";
    //     for(int j=i+1;j<=N;j++){
    //         ll num = pow(j,2) - pow(i,2);
    //         cout<<num<<" ";
    //         s1.insert(num);
    //     }
    //     cout<<"\n";
    // }
    // int ans=1;
    // cout<<s1.size()<<"\n";
    // for( auto x : s1) {
    //     cout<<x<<" ";
    //     ans++;
    //     if(ans==20) ans=0,cout<<"\n";
    // }
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}
