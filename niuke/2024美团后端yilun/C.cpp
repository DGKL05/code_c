#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>>tree;
vector<int>yanse;
int ans;

unordered_map<int, int> dfs(int idx, int pre) {
    // cout<<"idx = "<<idx<<" pre = "<<pre<<"\n";
    unordered_map <int, int> temp;
    temp[yanse[idx]] = 1;
    for (auto x : tree[idx]) {
        // cout<<idx<<" -> "<<x<<"\n";
        if (x == pre) continue;
        unordered_map <int, int> m1 = dfs(x, idx);

        for (auto [l, r] : m1) {
            temp[l] += r;
        }
    }
    int max_cnt = 0;

    for (auto [l, r] : temp) {
        max_cnt = max(max_cnt, r);
    }
    int num = 0;
    for (auto [l, r] : temp) {
        if (r == max_cnt) continue;
        if (r % 2 == 1) num ^= l;
    }
    ans = max(ans, num);
    // cout<<" ans = "<<ans<<"\n";
    return temp;
}

void test() {
    int n = 0;
    cin >> n;
    tree.resize(n);
    yanse.resize(n);
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        yanse[i] = val;
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        tree[u].push_back(v);
        tree[v].push_back(u);

    }
    // for(int i=0;i<n;i++){
    //     cout<<i+1<<" -> ";
    //     for(auto x:tree[i]){
    //         cout<<x+1<<" ";
    //     }
    //     cout<<"\n";
    // }
    // cout<<ans<<"\n";
    unordered_map<int, int>m1 = dfs(0, -1);
    cout << ans << "\n";
}

int main() {
    int T = 1;
    // cin>>T;
    while (T--) test();
    return 0;
}