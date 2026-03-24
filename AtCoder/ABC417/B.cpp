#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int m=0;
    cin>>n>>m;
    multiset<int>s1;
    for(int i=0;i<n;i++){
        int num=0;
        cin>>num;
        s1.insert(num);
    }
    // for(auto x:s1) cout<<x<<" ";
    for(int i=0;i<m;i++){
        int num=0;
        cin>>num;
        if(s1.find(num) != s1.end()){
            s1.erase(s1.find(num));
        }
    }
    for(auto x:s1) cout<<x<<" ";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}