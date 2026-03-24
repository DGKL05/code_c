#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    vector<int>arr(n+1,0);
    int idx_min = -1;
    int min_val=1e8;
    int idx_max = -1;
    int max_val=-1e8;
    
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        min_val = min(min_val , arr[i]);
        max_val = max(max_val , arr[i]);
    }
    cout<<1<<" "<<n<<" "<<max_val - min_val<<"\n";
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
