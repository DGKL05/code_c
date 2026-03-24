#include<bits/stdc++.h>
using namespace std;
using ll =long long;

bool check(vector<ll> &v1){
    ll num=v1[0];
    for(int i=1;i<v1.size();i++){
        if(v1[i]!=num) return true;
    }
    return false;
}

void test()
{
    int n=0;
    cin>>n;
    vector<ll>v1(n);
    for(int i=0;i<n;i++){
        cin>>v1[i];
        // cout<<v1[i]<<' ';
    }
    // cout<<"\n";
    ll ans=0;
    while(check(v1)){
        ans++;
        for(int i=0;i<n;i++){
            // cout<< v1[i] <<' '<< v1[((i+ans)%n)] << " " << (int)(v1[i]|v1[(i+ans)%n])<<"\n";
            v1[i]=(ll)v1[i]|v1[(i+ans)%n];
        }
        // for(int i=0;i<n;i++){
        //     cout<<v1[i]<<" ";
        // }
        // cout<<"\n";
    }
    cout<<ans<<"\n";
}

int main()
{
    // cout<<(int)(7|6)<<"\n";
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}