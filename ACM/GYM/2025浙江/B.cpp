#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N = 2e5+5;
bool v[N];

void solve(){
    int n,m;cin>>n>>m;
    for(int i = 1;i<=n;++i)v[i]=false;
    auto f = [&](int w){
        int ww = w;
        int ans = 0;
        for(int i = ww;i<=n;i+=ww){
            if(!v[i]){v[i]=1;ans++;}
        }
        return ans;
    };
    for(int i = 1;i<=m;++i){
        int k;cin>>k;
        if(v[k]){
            cout<<"the lights are already on!"<<endl;
            continue;
        }
        int kk = f(k);
        if(kk==0)cout<<"the lights are already on!"<<endl;
        else cout<<kk<<endl;
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    cin>>t;
    while(t--)solve();
}