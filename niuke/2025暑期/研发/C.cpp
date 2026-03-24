#include<bits/stdc++.h>
using namespace std;

using ll =long long;


void test()
{
    int n=0;int k=0;
    multimap<int,int>m1;
    map<int,int>m2;
    multimap<int,int>m3;
    map<int,int>m4;
    cin>>n>>k;
    vector<int>v1(n);
    for(int i=0;i<n;i++){
        cin>>v1[i];
        m1.insert(pair<int,int>(v1[i],i));
        m2[i]=v1[i];
    }
    for(int i=0;i<n;i++){
        m3.insert(pair<int,int>(v1[i]^k,i));
        m4[i]=v1[i]^k;
    }

    
    for(int j=0;j<n-1;j++){
        
        if(j%2==0){
            auto it=m3.begin();
            int idx=it->second;
            int num=it->first;
            if(m4.find(idx) != m4.end()) m4.erase(m4.find(idx));
            auto kt=m2.find(idx);
            int n1=kt->second;
            auto check=m1.find(n1);
            
            m1.erase(check);
            m2.erase(kt);
            m3.erase(it);
        }else{
            auto it=m1.begin();
            int idx=it->second;
            int num=it->first;
            if(m2.find(idx) != m2.end()) m2.erase(m2.find(idx));
            auto kt=m4.find(idx);
            int n1=kt->second;
            auto k=m3.find(n1);

            m3.erase(k);
            m4.erase(kt);
            m1.erase(it);
        }
    }


    if(n%2==1){
        auto it=m1.begin();
        cout<<(it->first)<<"\n";
    }else{
        auto it=m3.begin();
        cout<<it->first<<"\n";
    }
}

int main()
{
    int T=1;
    // cout<<(int)('z'-97)<<"\n";
    // cin>>T;
    while(T--) test();
    return 0;
}