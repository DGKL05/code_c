#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;ll x=0; ll y=0;
    cin>>n>>x>>y;
    multiset<ll>s1;
    set<ll>s2;
    map<int,int>m1;
    multimap<int,int>m2;
    for(int i=0;i<n;i++){
        ll num=0;
        cin>>num;
        m1[num]++;
        s1.insert(num);
        s2.insert(num);
    }
    for(auto [l,r] : m1){
        m2.insert(pair<int,int>(r,l));
    }
    if(s2.size()==1){
        cout<<"0\n";
        return ;
    }
    ll ans=1LL*(n-1)*y;
    
    auto it=s1.end();
    it--;
    
    ans=min(ans,(*it)*x);
    // s2.erase((*it));
    int idx=1;
    while(idx!=(n)){
        ll num=*it;
        it = s1.erase(it);
        if(s1.find(num) == s1.end()) s2.erase(num);
        ll temp=1LL*idx*y;
        // cout<<"idx = "<<idx<<" temp = "<<temp<<" size() = "<<s1.size()<<"\n";
        it--;
        if(s2.size()>=2) {
            temp+=(*it)*x;
        }
        ans=min(ans,temp);
        idx++;
    }
    auto lt=m2.end();
    lt--;
    ll temp=0;
    ll num=lt->second;
    // cout<<"num = "<< num << "\n";
    for(auto [l,r]:m2){
        if(r!=num) temp+=1LL*l*y;
        // cout<<"l = "<<l<<" r = "<<r<<"\n";
    }
    if(temp!=0) ans=min(ans,temp);
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