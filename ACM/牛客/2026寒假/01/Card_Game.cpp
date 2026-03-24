#include<bits/stdc++.h>
using namespace std;
using ll =long long;

const int N = 2*1e5+5;
const ll MOD = 998244353;
ll jie[N];
void f(){
    jie[0] = 1;
    for(int i=1;i<N;i++){
        jie[i]=jie[i-1]*(i)%MOD;
    }
}

void test()
{
    int n=0;
    cin>>n;
    vector<int>a(n),b(n);
    for(auto &x:a) cin>>x;
    for(auto &x:b) cin>>x;
    sort(a.begin() , a.end() ,greater<int>());
    ll ans = 0;
    int i=0;int j=0;
    while(i<n && j<n){
        if(a[i] > b[j]){
            i++;
            ans++;
        }else j++;
    }
    // cout<<"ans = "<<ans<<"\n";
    cout<<(1LL*jie[ans]%MOD*jie[n - ans]%MOD)%MOD<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    f();
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}