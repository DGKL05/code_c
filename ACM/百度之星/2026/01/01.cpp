#include<bits/stdc++.h>
using namespace std;
using ll = long long;


void test(){
    int n=0;int k=0;ll s=0;
    cin>>n>>k>>s;
    map<ll,ll>m1;
    for(int i=0;i<n;i++){
        ll a = 0;ll b = 0;
        cin>>a>>b;
        m1[a]+=b;
    }
    auto it = m1.begin();
    while(it!=m1.end()){
        
        if((it -> first) > s){
            if(k != 0){
                s*=2;
                k--;
                continue;
            }
            else break;
        }else {
            s+=it->second;
            it++;
        }

    }
    while(k > 0){
        s*=2;
        k--;
    }
    cout<<s<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin>>T;
    while(T--) test();
    return 0;
}