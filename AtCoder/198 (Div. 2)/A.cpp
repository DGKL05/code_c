#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    if(n<=2){
        cout<<1<<"\n"<<n<<"\n";
        return ;
    }
    if(n%2==1) n--;
    set<int>s1;
    for(int i=n;i>=2;i-=2){
        s1.insert(i);
    }
    cout<<s1.size()<<"\n";
    for(int x:s1) cout<<x<<' ';
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}