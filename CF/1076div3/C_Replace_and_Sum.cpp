#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int q=0;
    cin>>n>>q;
    vector<int>a(n),b(n);
    for(auto &x:a) cin>>x;
    for(auto &x:b) cin>>x;
    for(int i=0;i<n;i++){
        a[i] = max(a[i],b[i]);
    }
    int max_num = a[n-1];
    for(int i=n-1;i>=0;i--){
        max_num = max(max_num , a[i]);
        a[i] = max_num;
    }
    for(int i=1;i<n;i++){
        a[i] += a[i-1];
    }
    a.insert(a.begin(),0);
    while(q--){
        int l=0;int r=0;
        cin>>l>>r;
        l--;
        cout<<a[r] - a[l]<<" ";
    }
    cout<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}
