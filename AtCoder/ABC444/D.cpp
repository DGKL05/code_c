#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    vector<int>arr(n);
    int max_n=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        max_n = max( max_n , arr[i]);
    }
    // cout<<max_n<<"\n";
    vector<ll>ans(max_n , 0);
    for(auto x:arr){
        ans[0]++;
        if(x != max_n) ans[x]--;
    }
    // for(auto x:ans)
    for(int i=1;i<max_n;i++){
        ans[i] += ans[i-1];
    }
    // cout<<ans.size()<<"\n";
    // for(auto x:ans){
    //     cout<<x;
    // }
    // cout<<"\n";
    int temp = 0;
    vector<ll>v1;
    for(int i=0;i<max_n;i++){
        v1.push_back((ans[i] + temp) % 10);
        temp = (ans[i] + temp)/10;
    }
    if(temp!=0) v1.push_back(temp);
    // cout<<"size() = "<<v1.size()<<"\n";
    map<int,int>m1;
    for(int i=v1.size() - 1;i>=0;i--){
        m1[v1[i]]++;
        cout<<v1[i];   
    }
    // for(auto [l,r] : m1){
    //     cout<<l<<" "<<r<<"\n";
    // }
    // cout<<"1\n";
    cout<<"\n";
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