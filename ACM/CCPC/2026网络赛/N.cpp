#include<bits/stdc++.h>

using namespace std;
using ll = long long;

bool check(ll n, ll m, string &s1){

    if(m>=n*0.2 || m >= 50){
        return true;
    }else if(s1[0] - '0' >= 1 || s1[1] - '0' >= 4){
        return true;
    }else return false;
}

void test(){
    ll n=0;ll m=0;
    cin>>n>>m;
    string s1;
    cin>>s1;
    if(check(n,m,s1)){
        cout<<"YES\n";
    }else cout<<"NO\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin>>T;
    while(T--) test();
    return 0;
}