#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int k=0;
    cin>>n>>k;
    int num=0;
    vector<int>arr(n);
    for(auto &x:arr) {
        cin>>x;
        if(x == k) num++;
    }
    sort(arr.begin(),arr.end());
    int ans=0;
    set<int>s1;
    for(int i=0;i<n;i++){
        s1.insert(arr[i]);
    }
    for(auto x:s1){
        if(x == ans) ans++;
        else break;
    }
    // cout<<"ans = "<<ans<<"\n";
    if(s1.find(ans) != s1.end()) ans--;
    if(ans>=k){
        cout<<num<<"\n";
        return ;
    }
    int ans1=0;
    for(int i=0;i<k;i++){
        if(s1.find(i) == s1.end()) ans1++;
    }
    cout<<max(ans1,num)<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}