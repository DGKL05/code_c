#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int k=0;
    cin>>n>>k;
    string s1;
    cin>>s1;
    map<char,int>m1;
    for(int i=0;i<n;i++){
        m1[s1[i]]++;
    }
    ll ans=0;
    vector<int>v1;
    for(auto [l,r] : m1){
        v1.push_back(r);
    }
    sort(v1.begin(),v1.end());
    int idx=v1.size()-1;
    for(int i=0;i<k;i++){
        if(v1[idx]<3 || idx==-1){
            break;
        }else {
            ans+=v1[idx];
        }
        idx--;
    }
    cout<<n - ans<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}