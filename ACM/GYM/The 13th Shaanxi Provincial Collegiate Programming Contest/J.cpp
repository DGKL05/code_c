#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int k=0;
bool check(int num,int index,vector<bool> &fa){
    if(k<4-num) return false;
    for(int i=index;i<index+num;i++){
        // cout<<i<<" ";
        if(fa[i] == true) return false;
    }
    for(int i=index;i<index+num;i++){
        fa[i] = true;
    }
    return true;
}

void test()
{
    
    ll ans=0;
    cin>>k;
    string s1;
    cin>>s1;
    int n=s1.size();ws
    s1=' '+s1;
    vector<bool>fa(n+1,false);
    // cout<<s1<<'\n';
    for(int i=1;i<=n-3;i++){
        if(s1.substr(i,4)=="lose" && check(4,i,fa)) {
            ans++;
        }
    }

    for(int i=1;i<=n-2;i++){
        if((s1.substr(i,3)=="los" || s1.substr(i,3)=="ose" || s1.substr(i,3)=="lse" || s1.substr(i,3)=="loe") && k>0 && check(3,i,fa)) ans++,k--;
    }
    for(int i=1;i<=n-1;i++){
        // cout<< i <<" "
        if((s1.substr(i,2)=="lo" || s1.substr(i,2)=="ls" || s1.substr(i,2)=="le" || s1.substr(i,2)=="os" || s1.substr(i,2)=="oe" || s1.substr(i,2)=="se") && k>1 && check(2,i,fa)) ans++,k-=2;
    }
    for(int i=1;i<=n;i++){
        if((s1[i]=='l' || s1[i]=='o' || s1[i]=='s' || s1[i]=='e') && k>2 && check(1,i,fa)) ans++,k-=3;
    }
    // cout<<ans<<"\n";
    if(k>=4) ans+=(k/4);
    cout<<ans<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test();
    return 0;
}