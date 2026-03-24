#include<bits/stdc++.h>
using namespace std;
using ll =long long;

const int N = 2e5+5;

struct node{
    ll num;
    map<int,int>cnt;
};

void test()
{
    int n, m, k;
    cin >> k >> m >> n;
    vector<int> good(n);
    while (k--) {
        int x;
        cin >> x;
        x--;
        good[x] = 1;
    }
    map<pair<int, int>, int> edge;
    vector<int> deg(n);
    int sum = 0;
    while (m--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if (x > y) swap(x, y);
        if (good[x] && good[y]) {
            sum++;
        } else if (x == y) {
            deg[x]++;
        } else if (good[x]) {
            deg[y]++;
        } else if (good[y]) {
            deg[x]++;
        } else {
            edge[{ x, y }]++;
        }
    }
    int ans = 0;
    for (auto [e, w] : edge) {
        auto [x, y] = e;
        ans = max(ans, deg[x] + deg[y] + w);
    }
    // cout<<ans<<"\n";
    sort(deg.begin(), deg.end(), greater<>());
    // if(n!=1) cout<<deg[0]<<" "<<deg[1]<<"\n";
    ans = max(ans, n == 1 ? deg[0] : deg[0] + deg[1]);
    ans += sum;
    cout << ans << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}