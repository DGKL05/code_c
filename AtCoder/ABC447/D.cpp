#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    string s1;
    cin>>s1;
    int n = s1.size();
    ll ans=0;
    map<char,vector<int>>m1;
    for(int i=0;i<n;i++){
        m1[s1[i]].push_back(i);
    }
    if(m1.find('A') == m1.end() || m1.find('B') == m1.end() || m1.find('C') == m1.end()){
        cout<<"0\n";
        return ;
    }
    vector<int> i = m1.find('A')->second;
    vector<int> j = m1.find('B')->second;
    vector<int> k = m1.find('C')->second;
    int n1 = i.size();
    int n2 = j.size();
    int n3 = k.size();
    if(n1 == 0 || n2 == 0 || n3 == 0){
        cout<<"0\n";
        return ;
    }
    int j1 = 0;int k1 = 0;int i1=0;
    while(i1 < n1 && j1 < n2 && k1 < n3){
        while(i[i1] >= j[j1]) j1++;
        if(j1 >= n2) break;

        while(j[j1] >= k[k1]) k1++;
        if(k1 >= n3) break;
        ans++;
        i1++;
        k1++;
        j1++;
    }
    cout<<ans<<"\n";
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