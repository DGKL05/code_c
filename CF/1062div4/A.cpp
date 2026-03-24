#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    set <int> s1;
    for(int i=0;i<4;i++){
        int num=0;cin>>num;
        s1.insert(num);
    }
    if(s1.size() == 1){
        cout<<"Yes\n";
    }else cout<<"No\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}