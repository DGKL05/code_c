#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;
    sort(arr.begin() , arr.end());
    double n1 = (n-1)*0.8;
    int ans=0;
    for (int i = 0; i < n; ++i) {
        int idx = 0;
        int temp = arr[i];
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            if (arr[j] <= temp) {
                idx++;
            }
        }
        if (idx >= n1) {
            ans += temp;
        }
    }
    cout<<ans<<"\n";
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