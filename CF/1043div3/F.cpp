#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const int N = 1e6;
set<int>s1;
void test()
{
    int n=0;
    while(n!=(-1)){
        cin>>n;
        if(n<0) return ;
        if(s1.find(n)!=s1.end()){
            cout<<"YES\n";
        }else cout<<"NO\n";
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    ll num=1;
    int idx=1;
    int temp=1;
    while(num<=N){
        cout<<num<<" ";
        s1.insert(num);
        idx++;
        temp*=idx;
        num+=temp;
        
    }
    while(T--) test(); 
    return 0;
}