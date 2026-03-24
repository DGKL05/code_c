#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    vector<vector<int>>arr(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int min_num = INT_MAX;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 1) {
                break;
            }
            cnt++;
        }
        min_num = min(min_num, cnt);
        // int ans = (i + 1) * min_num;
        ans = max(ans,1LL*(i + 1) * min_num);
    }
    cout << ans << endl;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}