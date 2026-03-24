#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;ll ans=0;
    cin>>n;
    set<int>s1;
    set<int>s2;
    vector<int>v1(n);
    for(int i=0;i<n;i++){
        int num=0;
        cin>>num;
        s1.insert(num);
        s2.insert(num);
        if(s1.size()==s2.size()) {
            ans++;
            s2.clear();
        }
    }
    cout<<ans<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}