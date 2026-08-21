#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void test(){
    int a=0;int b=0;
    cin>>a>>b;
    bool fa = false;
    if(a+b == 9 || (a- b) == 9 || a*b == 9 ||( (a/b) == 9 && a%b == 0)) fa = true;
    if(fa) cout<<"Nine\n";
    else cout<<"Nein\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin>>T;
    while(T--) test();
    return 0;
}