#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    int q=0;
    cin>>q;
    vector<vector<ll>>arr(q,vector<ll>(2));
    for(int i=0;i<q;i++){
        cin>>arr[i][0]>>arr[i][1];
    }
    vector<ll>ans(n,0);
    ll cnt=0;
    for(int i=0;i<q;i++){
        cnt += arr[i][0]/n;
        if((arr[i][0])%n == 0) continue;
        if(((0+arr[i][1])%n) > (arr[i][0] + arr[i][1] - 1)%n+1){
            ans[0]++;
            if((arr[i][0] + arr[i][1] - 1)%n+1 != n) ans[(arr[i][0] + arr[i][1] - 1)%n+1]--;
            ans[(0+arr[i][1])%n]++;
            continue;
        }
        ans[(0+arr[i][1])%n]++;
        if((arr[i][0] + arr[i][1] - 1)%n+1 != n) ans[(arr[i][0] + arr[i][1] - 1)%n+1]--;
        // cout<<"idx = "<<(0+arr[i][1])%n<<" idx = "<<(arr[i][0] + arr[i][1])%n+1<<"\n";
    }
    for(int i=1;i<n;i++){
        ans[i]+=ans[i-1];
    }
    // cout<<"\n";
    // cout<<"cnt = "<<cnt<<"\n";
    for(auto x:ans) cout<<x + cnt<<" ";
    cout<<"\n";
}
//0 1 2 3  
//2 3 4 5
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