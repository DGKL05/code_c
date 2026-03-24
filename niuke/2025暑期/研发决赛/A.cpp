#include <bits/stdc++.h>
using namespace std;
using ll =long long;
void test()
{
    ll n=0;ll x=0;ll y=0;ll cnt_0=0;ll cnt_1=0;
    cin>>n>>x>>y;
    vector<ll>v1(n);
    for(auto &x:v1){
        cin>>x;
        if(x==0) cnt_0++;
        else cnt_1++;
    }
    if(cnt_1==n){
        for(int i=0;i<y;i++){
            cout<<"1 ";
        }
        for(int i=0;i<x;i++){
            cout<<"0";
            if(i!=(x-1)) cout<<" ";
        }
        cout<<"\n";
        return ;
    }
    if(cnt_1 == 0 || ((x+y)!=(n-1))){
        cout<<"-1\n";
        return ;
    }
    if(v1[n-1]==1){
        if(x!=0){
            for(int i=0;i<y;i++){
                cout<<"1 ";
            }
            for(int i=0;i<x;i++){
                cout<<"0";
                if(i!=(x-1)) cout<<" ";
            }
            cout<<"\n";
            return ;
        }else {
            if(cnt_1 == n){
                for(int i=0;i<y;i++){
                    cout<<"1";
                    if(i!=(y-1)) cout<<" ";
                }
                cout<<"\n";
                return ;
            }else {
                cout<<"-1\n";
                return ;
            }
        }
    }else {
        ll idx=-1;
        for(int i=0;i<n;i++){
            if(v1[i]==1) idx=i;
        }
        if(x==0){
            cout<<"-1\n";
            return ;
        }
        if(idx==0){
            for(int i=0;i<x;i++){
                cout<<"0 ";
            }
            for(int i=0;i<y;i++){
                cout<<"1 ";
            }
            cout<<"\n";
            return ;
        }else {
           
        }
    }
}

int main() {
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) test();
    return 0;
}