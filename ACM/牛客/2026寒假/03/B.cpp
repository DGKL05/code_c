#include<bits/stdc++.h>
using namespace std;
using ll =long long;

vector<ll> f(ll x) {
    vector<ll> a;
    if (x == 1) return a;
    if (x % 2 == 0) {
        a.push_back(2);
        while (x % 2 == 0) {
            x /= 2;
        }
    }
    for (ll i = 3; i * i <= x; i += 2) {
        if (x % i == 0) {
            a.push_back(i);
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x > 1) {
        a.push_back(x);
    }
    return a;
}

void test()
{
    int n=0;
    cin>>n;
    vector<ll>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    map<ll,int>m1;
    for(int i=0;i<n;i++){
        vector<ll>a = f(arr[i]);
        for(auto x:a){
            if(m1.find(x) != m1.end()){
                cout<<arr[i] <<" "<<arr[m1.find(x)->second]<<"\n";
                return ;
            }
            m1[x] = i;
        }
    }
    cout<<"-1\n";
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