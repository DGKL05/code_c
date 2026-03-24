#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<string> arr;
vector<vector<bool>> fa;
vector<vector<pair<int,int>>> jump;
int h, w;
int ans = -1;  
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

struct node {
    int x, y;
    int num;
};

void bfs(int x, int y) {
    if(x == h-1 && y == w-1) {
        ans = 0;
        return;
    }
    queue<node> q1;
    q1.push({x, y, 0});
    fa[x][y] = true;
    
    while(!q1.empty()) {
        node a = q1.front();
        q1.pop();
        
        for(int i = 0; i < 4; i++) {
            int tx = a.x + dx[i];
            int ty = a.y + dy[i];

            if(tx < 0 || tx >= h || ty < 0 || ty >= w) continue;
            if(fa[tx][ty]) continue;
            if(arr[tx][ty] == '#') continue;
            
            if(tx == h-1 && ty == w-1) {
                ans = a.num + 1;
                return;
            }
            
            fa[tx][ty] = true;
            q1.push({tx, ty, a.num + 1});
        }
        char c = arr[a.x][a.y];
        if(c >= 'a' && c <= 'z') {
            for(auto [l, r] : jump[c - 'a']) {
                if(l == a.x && r == a.y) continue;
                if(fa[l][r]) continue;
                if(l == h-1 && r == w-1) {
                    ans = a.num + 1;
                    return;
                }
                
                fa[l][r] = true;
                q1.push({l, r, a.num + 1});
            }
            // jump[c - 'a'].clear();
        }
    }
}

void test() {

    cin >> h >> w;
    arr.resize(h);
    fa.assign(h, vector<bool>(w, false));
    jump.assign(26, vector<pair<int,int>>());
    
    for(int i = 0; i < h; i++) {
        cin >> arr[i];
        for(int j = 0; j < w; j++) {
            char c = arr[i][j];
            if(c >= 'a' && c <= 'z') {
                jump[c - 'a'].push_back({i, j});
            }
        }
    }
    if(arr[0][0] == '#' || arr[h-1][w-1] == '#') {
        cout << -1 << "\n";
        return;
    }
    
    bfs(0, 0);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int T = 1;
    // cin >> T;
    while(T--) test();
    return 0;
}