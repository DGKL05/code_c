#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int ans_x,ans_y,x,y;
    cin>>ans_x>>ans_y>>x>>y;
    if(x >= ans_x && x< ans_x+100 && y >= ans_y && y< ans_y+100 ){
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
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