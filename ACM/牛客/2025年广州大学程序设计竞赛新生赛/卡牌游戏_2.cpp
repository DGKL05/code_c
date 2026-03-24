#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int m=0;
    cin>>n>>m;
    vector<int>a(n) , b(m);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    set<int>s1;
    for(int i=0;i<n;i++) s1.insert(a[i]);
    int num = 0;
    ll ans = 0;
    for(int i=0;i<m;i++){
        if(s1.find(b[i]) != s1.end()) {
            num++;
            ans+=b[i];
        }
    }
    if((n - num) <= (m - num)){
        cout<<0<<" "<<ans<<"\n";
    }else {
        cout<<ans<<" "<<0<<"\n";
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