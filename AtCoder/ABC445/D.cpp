#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int H, W, N;
    cin >> H >> W >> N;
    vector<int> h(N), w(N);
    for (int i = 0; i < N; i++) cin >> h[i] >> w[i];
    vector<int> ord_h(N), ord_w(N);
    iota(ord_h.begin(), ord_h.end(), 0);
    sort(ord_h.begin(), ord_h.end(), [&](int x, int y) { return h[x] > h[y]; });
    iota(ord_w.begin(), ord_w.end(), 0);
    sort(ord_w.begin(), ord_w.end(), [&](int x, int y) { return w[x] > w[y]; });

    vector<int> ans_x(N, -1), ans_y(N, -1);
    vector<bool> used(N, false);
    auto ith = ord_h.begin();
    auto itw = ord_w.begin();
    for (int rem = N; rem > 0; rem--) {
        while (used[*ith]) ith++;
        while (used[*itw]) itw++;
        int i = h[*ith] == H ? *ith : *itw;
        ans_x[i] = H - h[i] + 1;
        ans_y[i] = W - w[i] + 1;
        used[i] = true;
        if (h[i] == H) {
            W -= w[i];
        } else {
            H -= h[i];
        }
    }
    for (int i = 0; i < N; i++) cout << ans_x[i] << " " << ans_y[i] << "\n";
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