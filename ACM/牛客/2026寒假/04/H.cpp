#include<bits/stdc++.h>
using namespace std;
using ll =long long;

int dirs[13][2] = {
    {0,0},{0,1}, {0,-1}, {1,0}, {-1,0},  
    {0,2}, {0,-2}, {1,1}, {1,-1}, {-1,1}, {-1,-1},{2,0}, {-2,0} 
};

void test()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<ll>>arr(n+1 , vector<ll>(m+1)) , sum(n+1 , vector<ll>(m+1));
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            sum[i][j] = 0;
            for (int d = 0;d<13;d++) {
                int dx = dirs[d][0];
                int dy = dirs[d][1];
                int x = i + dx;
                int y = j + dy;
                if (x >= 1 && x <= n && y >= 1 && y <= m) {
                    sum[i][j] += arr[x][y];
                }
            }
        }
    }

    ll max_val = -1;
    int max_x = 1, max_y = 1;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            if (sum[i][j] > max_val) {
                max_val = sum[i][j];
                max_x = i;
                max_y = j;
            }
        }
    }
    while (q--) {
        int x, y;
        ll z;
        cin >> x >> y >> z;
        for (int d = 0;d < 13;d++) {
            int dx = dirs[d][0];
            int dy = dirs[d][1];
            int i = x + dx;
            int j = y + dy;
            if (i >= 1 && i <= n && j >= 1 && j <= m) {
                sum[i][j] += z;
                if (sum[i][j] > max_val) {
                    max_val = sum[i][j];
                    max_x = i;
                    max_y = j;
                }
            }
        }
        cout << max_x << " " << max_y << "\n";
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