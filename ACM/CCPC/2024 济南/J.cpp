#include<bits/stdc++.h>
using namespace std;
using ll =long long;

struct node{
    int a,b,c;
};

void test()
{
    vector<int>x(100005);
    vector<int>y(100005);
    vector<int>z(100005);
    int n=0;
    cin>>n;
    map<int,int>m1;
    vector<node>arr(n);
    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        x[a]++;y[b]++;z[c]++;
        arr[i].a=a;
        arr[i].b=b;
        arr[i].c=c;
    }
    for(int i=0;i<n;i++){
        int num=0;
        num=x[ arr[i].a ]-1;
        num=max({num,y[ arr[i].b ]-1,z[ arr[i].c ]-1});
        m1[num]++;
        // cout<<num<<"\n";
    }
    // for(auto [l,r] : m1){
    //     cout<<l<<" "<<r<<"\n";
    // }
    auto it = m1.begin();
    int k=0;
    int ans=0;
    for(k;k<n;k++){
        if(it==m1.end()){
            cout<<ans<<" ";
            continue;
        }
        while((it->first < k) && it!=m1.end()){
            ans+=it->second;
            it++;
        }
        cout<<ans<<" ";
    }
    cout<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}