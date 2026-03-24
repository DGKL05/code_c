#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int m=0;
    cin>>n>>m;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int q=0;
    cin>>q;
    while(q--){
        vector<int>temp;
        int num = -1;
        while(num!=0){
            cin>>num;
            if(num!=0) temp.push_back(num);
        }
        map<int,int>m1;
        for(auto x:temp){
            m1[arr[x-1]]++;
        }
        // for(auto [l,r] : m1){
        //     cout<<"B"<<l<<"-"<<r<<" ";
        // }
        auto it = m1.begin();
        while(it != m1.end()){
            cout<<"B"<<it->first<<"-"<<it->second;
            it++;
            if(it != m1.end()) cout<<" ";
        }
        if(q!=0) cout<<"\n";
    }
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