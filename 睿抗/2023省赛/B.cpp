#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int m=0;
    cin>>n>>m;
    map<string,char>m1;
    map<string,int>m2;
    for(int i=0;i<n;i++){
        string s1;char a;
        cin>>s1>>a;
        m1[s1]=a;
        m2[s1]=s1.size();
    }
    // for(auto [l,r] : m1) cout<<l<<" "<<r<<"\n";
    while(m--){
        // cout<<m<<" --- \n";
        string str;
        cin>>str;
        int ans=0;int k=0;string temp;bool fa=true;
        auto it=m1.find(str);
        if(it!=m1.end()) {
            cout<<it->second<<"\n";
            continue;
        }
        for(auto [l,r] : m1){
            // cout<<"sub == "<<str.substr(0,l.size())<<"\n";
            if(str.substr(0,l.size()) == l) {
                if(ans == 1) {
                    ans=-1;
                    fa=false;
                }
                ans=1, k=l.size(),temp=r;
                // cout<<"temp == "<<temp<<"\n";
            }
        }
        string temp1;
        if(ans==1){
            for(auto [l,r] : m1){
                if(str.substr(k) == l){
                    if(ans==2){
                        ans=-1;
                        fa=false;
                    }
                    // cout<<temp<<l<<"\n";
                    temp1=r;
                    ans=2;
                }
            }
        }
        if(ans!=2 || fa==false) cout<<"D\n";
        else cout<<temp<<temp1<<"\n";
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