#include<bits/stdc++.h>

using namespace std;

void test(){
    int n=0;
    cin>>n;
    string s1;
    cin>>s1;
    for(auto &x:s1){
        x = (x+n)%123;
        if(x<97) x+= 97;
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