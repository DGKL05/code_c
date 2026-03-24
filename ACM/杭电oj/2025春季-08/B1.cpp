#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using node = tuple<int, int, int, int>;
#define RAN(i, f, t) for (int i=f; i<(t); i++)

pii movs[] = {
    {-1, 0}, {1, 0},
    {0, 1}, {0, -1}
};

int t, n, m, R, X;
int main() {
    cin>>t;
    while(t--) {
        cin>>n>>m;
        auto g = vector(n+1, vector(m+1, ' '));
        // auto vis = vector(n+1, vector(m+1, false));
        vector<vector<int>>vis(n+1,vector<int>(m+1));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++){
                vis[i][j]=0;
            }
        }

        RAN(i, 1, n+1) {
            cin>>R;
            RAN(j, 1, R) cin>>X, g[i][X] = 'x';
        }

         
        auto geth  = [&] (int x, int y) {
            return abs(x - m) + abs(x - y);
        };

        auto inside  = [&] (int x, int y) {
            return x >= 1 && x <= n && y >= 1 && y <= m && g[x][y] != 'x' ;
        };

        auto astart =[&] () {
            priority_queue<node, vector<node>, greater<node>> Q;
            RAN(i, 1, n+1) if (g[i][1] != 'x')
                Q.push({geth(i, 1), i, 1, 1});
            while(!Q.empty()) {
                auto [v, x, y, path] = Q.top(); Q.pop();
                //cout<<x<<" "<<y<<"\n";
                vis[x][y] = 1;
                if (y == m) return path;
                for (auto [dx, dy] : movs) if (inside(dx + x, dy + y)){
                    if (vis[x+dx][y+dy]) continue;
                    Q.push({v+1+geth(dx + x, dy + y), dx + x, dy + y, path+1});
                }
                
            }
            return -1;
        };

        cout<<astart()<<"\n";

    }

}