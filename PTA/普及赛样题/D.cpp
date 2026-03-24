#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int num = 0;
    int idx = 1;
    while(cin>>num){
        if(num == 250) {
            cout<<idx<<"\n";
            return ;
        }
        ++idx;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}