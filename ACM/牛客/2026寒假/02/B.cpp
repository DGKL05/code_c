#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    map<ll,int>m1;
    map<ll,vector<int>>m2;
    for(int i=0;i<n;i++){
        ll num = 0;
        cin>>num;
        m1[num] ++;
        m2[num].push_back(i);
    }
    auto it = m1.end();
    it --;
    
    if(it->second & 1){
        vector<int>ans(n , 0);
        auto x = m2.end();
        x--;
        for(auto X : x->second){
            ans[X] = 1;
        }
        for(auto X:ans) cout<<X;
        cout<<"\n";
        return ;
    }
    vector<int>ans(n , 1);
    auto x = m2.end();
    x--;
    for(auto X : x->second){
        ans[X] = 0;
    }
    for(auto X:ans) cout<<X;
    cout<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}