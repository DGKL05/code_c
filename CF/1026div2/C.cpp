#include <bits/stdc++.h>
using namespace std;

struct O { int l, r; };

void test() {
    int n; cin >> n;
    vector<int> d(n);
    for (auto& x : d) cin >> x;
    vector<O> o(n);
    for (int i = 0; i < n; ++i) 
        cin >> o[i].l >> o[i].r;

    vector<int> lo(n), hi(n);
    int cl = 0, ch = 0; // current_low/high
    
    // 正向处理
    for (int i = 0; i < n; ++i) {
        int li = o[i].l, ri = o[i].r;
        if (d[i] >= 0) { // 已知变化量
            int nl = cl + d[i], nh = ch + d[i];
            nl = max(nl, li), nh = min(nh, ri);
            if (nl > nh) {
                cout<<"-1\n";
                return ;
            }
            lo[i] = cl = nl, hi[i] = ch = nh;
        } else { // 未知变化量
            int nl = cl + 0, nh = ch + 1;
            nl = max(nl, li), nh = min(nh, ri);
            if (nl > nh) {
                cout<<"-1\n";
                return ;
            }
            lo[i] = cl = nl, hi[i] = ch = nh;
        }
    }

    vector<int> a;
    cl = lo.back(), ch = hi.back();
    
    // 逆向处理
    for (int i = n-1; i >= 0; --i) {
        if (d[i] != -1) {
            a.push_back(d[i]);
            int pl = cl - d[i], ph = ch - d[i];
            if (i == 0) {
                if (pl <= 0 && 0 <= ph) cl = ch = 0;
                else {
                    cout<<"-1\n";
                    return ;
                }
            } else {
                pl = max(pl, lo[i-1]), ph = min(ph, hi[i-1]);
                if (pl > ph) {
                    cout<<"-1\n";
                    return ;
                }
                cl = pl, ch = ph;
            }
        } else {
            bool f = 0;
            // 优先尝试选1
            int cd = 1;
            int plc = cl - cd, phc = ch - cd;
            if (i > 0) {
                plc = max(plc, lo[i-1]);
                phc = min(phc, hi[i-1]);
            } else {
                if (plc > 0 || phc < 0) plc = 1, phc = 0;
                else plc = phc = 0;
            }
            if (plc <= phc) {
                a.push_back(1);
                cl = plc, ch = phc;
                f = 1;
            } else { // 尝试选0
                cd = 0;
                plc = cl - cd, phc = ch - cd;
                if (i > 0) {
                    plc = max(plc, lo[i-1]);
                    phc = min(phc, hi[i-1]);
                } else {
                    if (plc > 0 || phc < 0) plc = 1, phc = 0;
                    else plc = phc = 0;
                }
                if (plc <= phc) {
                    a.push_back(0);
                    cl = plc, ch = phc;
                    f = 1;
                }
            }
            if (!f){
                cout<<"-1\n";
                return ;
            }
        }
    }
    if (cl != 0 || ch != 0) {
        cout<<"-1\n";
        return ;
    }

    reverse(a.begin(), a.end());
    for (int x : a) cout << x << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) test();
    return 0;
}