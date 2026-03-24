#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int k=0;ll ans=0;
    cin>>n>>k;
    vector<int>v1(n);
    for(int i=0;i<n;i++){
        cin>>v1[i];
    }
    sort(v1.begin(),v1.end());
    multiset<int>s1;
    for(int x:v1) cout<<x<<' ';
    cout<<"\n";
    for(int i=0;i<n-1;i++){
        s1.insert(v1[i+1]-v1[i]);
        cout<<v1[i+1]-v1[i]<<" ";
    }
    if(k==2){
        auto it=s1.begin();
        cout<<(1LL)*((*it)*(*it))<<"\n";
        return ;
    }else{
        auto it=s1.begin();
        auto ik=s1.end();
        ik--;
        cout<<(1LL)*(*it)*(*ik)<<"\n";
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int t=1;
    // cin>>t;
    while(t--) test();
    return 0;
}