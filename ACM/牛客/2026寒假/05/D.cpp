#include<bits/stdc++.h>
using namespace std;
using ll =long long;

const ll MOD = 1e9+7;
struct node {
    ll w;
    ll c;
};

void test()
{
    int n=0;
    cin >> n;
    auto cmp = [](const node& a, const node& b) {
        return a.w > b.w;
    };
    priority_queue<node, vector<node>, decltype(cmp)> pq(cmp);
    for (int i = 0; i < n; i++) {
        ll c=0;ll w=0;
        cin >> c >> w;
        pq.push({w, c});
    }

    ll ans = 0;
    while (true) {
        if (pq.size() == 1) {
            if (pq.top().c == 1) 
                break;
        }
        node a = pq.top();
        pq.pop();
        if (a.c >= 2) {
            if (pq.empty() || (a.w * 2 <= pq.top().w)) {
                ll cnt = a.c / 2;
                ll temp = a.c - (a.c % 2);
                ans = (ans + a.w * temp) % MOD;
                if (a.c % 2) {
                    pq.push(node{a.w, 1});
                }
                if (cnt > 0) {
                    pq.push(node{a.w * 2, cnt});
                }
                continue;
            }
        }
        if (pq.empty()) {
            pq.push(a);
            break;
        }
        node b = pq.top();
        pq.pop();
        ll min_c = min(a.c, b.c);
        ans = (ans + min_c * (a.w + b.w)) % MOD;
        if (a.c > min_c) {
            pq.push(node{a.w, a.c - min_c});
        }
        if (b.c > min_c) {
            pq.push(node{b.w, b.c - min_c});
        }
        pq.push(node{a.w + b.w, min_c});
    }
    cout<< ans <<"\n";
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