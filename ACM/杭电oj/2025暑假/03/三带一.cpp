#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    const int n = 13;
    int a[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    auto check = [&](int ans) {
        int x[n] {};
        int need = ans;
        for (int i = 0; i < n; i++) {
            if (a[i] >= ans) {
                int more = std::min((a[i] - ans) / 2, a[i] / 3);
                int t = std::min(need, more);
                need -= t;
                x[i] += t;
            }
            int cur = std::min(a[i] - 3 * x[i], ans - x[i]);
            while (3 * (x[i] + 1) <= a[i] && need) {
                int nxt = std::min(a[i] - 3 * x[i] - 3, ans - x[i] - 1);
                if (nxt == cur - 1) {
                    x[i]++;
                    need--;
                    cur = nxt;
                } else {
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            int cur = std::min(a[i] - 3 * x[i], ans - x[i]);
            while (3 * (x[i] + 1) <= a[i] && need) {
                int nxt = std::min(a[i] - 3 * x[i] - 3, ans - x[i] - 1);
                if (nxt == cur - 2) {
                    x[i]++;
                    need--;
                    cur = nxt;
                } else {
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            int more = a[i] / 3 - x[i];
            int t = std::min(need, more);
            need -= t;
            x[i] += t;
        }
        
        if (need) {
            return false;
        }
        
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += std::min(a[i] - 3 * x[i], ans - x[i]);
        }
        return sum >= ans;
    };
    
    int lo = 0, hi = std::accumulate(a, a + 13, 0) / 4;
    while (lo < hi) {
        int x = (lo + hi + 1) / 2;
        if (check(x)) {
            lo = x;
        } else {
            hi = x - 1;
        }
    }
    std::cout << lo << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}