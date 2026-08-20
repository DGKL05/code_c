#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void test(){
    ll n=0;
    cin>>n;
    if(n == 0){
        cout<<0<<"\n";
        return ;
    }
    cout<<pow((n-1),2)/4<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin>>T;
    while(T--) test();
    return 0;
}