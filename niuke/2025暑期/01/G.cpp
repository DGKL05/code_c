#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int q=0;int a=0;
    cin>>n>>q;
    string s1;
    cin>>s1;
    while(q--){
        string str;int a=0;vector<int>v1;
        cin>>str>>a;
        int n2=str.size();
        for(int i=0;i<n2;i++){
            if(s1[i+a-1] == str[i]) v1.push_back(i);
        }
        // for(auto x: v1) cout<<x+1<<" ";
        // cout<<"\n";
        ll ans=v1.size();
        int n1=ans;int temp=0;
        for(int i=1;i<n1;i++){
            if(v1[i-1]+1 == v1[i]) temp++;
            else {
                ll k=temp;
                ans+=((k+1)*(k)/2);
                temp=0;
            }
        }
        ll k=temp;
        // cout<<k<<"\n";
        ans+=((k+1)*(k)/2);
        cout<<ans<<"\n";
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}