#include<bits/stdc++.h>

using namespace std;

void test(){
    string s1;
    cin>>s1;
    for(auto &x:s1){
        if(x>=97 && x<=122){
            x-=32;
        }
    }
    cout<<s1<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin>>T;
    while(T--) test();
    return 0;
}