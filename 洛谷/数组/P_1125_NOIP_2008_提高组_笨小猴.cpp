#include<bits/stdc++.h>

using namespace std;

void test(){
    string s1;
    cin>>s1;
    map<char,int>m1;
    for(auto x:s1){
        m1[x]++;
    }
    int ma=0;
    int mi=1e8;
    for(auto [l,r] : m1){
        ma = max(r,ma);
        mi = min(r,mi);
    }
    if(ma - mi <= 1){
        cout<<"No Answer\n0\n";
        return ;
    }
    int num = ma - mi;
    for(int i=2;i<num;i++){
        if(num%i == 0){
            cout<<"No Answer\n";
            cout<<0<<"\n";
            return ;
        }
    }
    cout<<"Lucky Word\n";
    cout<<num<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin>>T;
    while(T--) test();
    return 0;
}