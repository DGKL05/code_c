#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void test()
{
    int n=0;
    cin>>n;
    double ans=0;
    map<int,vector<string>>m1;
    for(int i=0;i<n;i++){
        string s1;
        int num=0;
        cin>>s1>>num;
        m1[num].push_back(s1);
        ans+=1.00*num;
    }
    ans/=n;
    // cout<<ans<<"\n";
    double temp = 0;
    vector<string>ans1;
    for(auto [l,r] : m1){
        // cout<<abs(l - ans)<<"\n";
        if(temp < abs(l - ans)){
            temp = abs(l - ans);
        }
    }
    for(auto [l,r] : m1){
        // cout<<abs(l - ans)<<"\n";
        if(temp == abs(l - ans)){
            for(auto x:r) ans1.push_back(x);
        }
    }
    cout<<ans1.size()<<"\n";
    for(auto x:ans1){
        cout<<x<<"\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin>>T;
    while(T--) test();
    return 0;
}