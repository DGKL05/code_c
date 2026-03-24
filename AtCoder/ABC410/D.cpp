#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1005;
ll num = 1e18; 
bool dist[N][1050];

struct node {
    int next;
    ll val;
};

vector<vector<node>> v1(N);
int n;
bool tt = false;
void bfs() {
    queue<node> q1;

    dist[1][0] = true;
    q1.push({1, 0});
    
    while (!q1.empty()) {
        node a = q1.front(); q1.pop();

        for (auto [net, val] : v1[a.next]) {
            // if (net == a.next) continue; 
            ll new_val = a.val ^ val; 
            if (!dist[net][new_val]) {
                dist[net][new_val] = true;
                q1.push({net, new_val});
            }
        }
    }
}

void test() {
    int m;
    cin >> n >> m;

    num = 1e18; 
    
    for (int i = 0; i < m; i++) {
        int a, b;
        ll val;
        cin >> a >> b >> val;
        v1[a].push_back({b, val});
        // v1[b].push_back({a, val});
    }
    
    bfs();
    for(int i=0;i<=1024;i++){
        if(dist[n][i]) {
            cout<<i<<"\n";
            return ;
        }
    }
    cout<<"-1\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T; 
    while (T--) test();
    return 0;
}