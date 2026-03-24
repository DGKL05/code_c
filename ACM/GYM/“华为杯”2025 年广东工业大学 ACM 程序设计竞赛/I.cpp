#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n1=0;int n2=0;
    cin>>n1>>n2;
    string s1,s2;
    cin>>s1>>s2;
    int r=-1;ll ans=0;
    for(int i=0;i<n1-n2+1;i++){
        if(s1.substr(i,n2) == s2){
            if(r==-1){
                r=i+n2-1;
                ans++;
            }
        }
        if(i>=r) r=-1;
    }
    cout<<ans<<'\n';
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}
