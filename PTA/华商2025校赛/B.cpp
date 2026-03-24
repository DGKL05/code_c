#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void test()
{
    int n=0;
    cin>>n;
    if(n>100){
        cout<<"Gong xi nin! Nin de ti zhong yue wei: 100 duo jin\n";
        return ;
    }else {
        if(n%10 == 0){
            n = n - 10;
        }else{
            n = n/10*10;
        }
        cout<<"Gong xi nin! Nin de ti zhong yue wei: "<<n<<" duo jin\n";
    }
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