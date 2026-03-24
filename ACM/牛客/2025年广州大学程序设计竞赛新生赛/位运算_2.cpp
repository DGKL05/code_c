#include<bits/stdc++.h>
using namespace std;
using ll =long long;

int get(int num){
    int ans=0;
    while(num){
        ans++;
        num>>=1;
    }
    return ans;
}

bool check(int a,int b,int c){
    return (max(get(a) , get(b)) >= get(c)) ? true : false;
}

void test()
{
    int a=0;int b=0;int c=0;
    cin>>a>>b>>c;
    cout<<(((check(a,b,c)) == true) ? "YES\n" : "NO\n");
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