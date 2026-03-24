#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    string s1;
    for(int i=0;i<n;i++){
        ll l;string a;
        cin>>a>>l;
        if(l>100 || (s1.size()+l) >100) {
            cout<<"Too Long\n";
            return ;
        }
        for(int j=0;j<l;j++) s1+=a;
    }
    if(s1.size()>100) cout<<"Too Long\n";
    else cout<<s1<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}