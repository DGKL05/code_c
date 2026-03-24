#include<bits/stdc++.h>
using namespace std;
using ll =long long;
using ull = unsigned long long;

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

void test()
{
    int n;
    std::cin >> n;
    
    std::vector<std::pair<int, ull>> a;
    for (int i = 0; i < n; i++) {
        int l, r;
        std::cin >> l >> r;
        r++;
        ull x = rng();
        a.emplace_back(l, x);
        a.emplace_back(r, x);
    }
    std::sort(a.begin(), a.end());
    
    int lst = -1;
    ull cur = 0;
    
    std::vector<ll> s {0};
    for (auto [i, x] : a) {
        if (i > lst) {
            s.push_back(cur);
        }
        lst = i;
        cur ^= x;
    }
    
    std::sort(s.begin(), s.end());
    int ans = std::unique(s.begin(), s.end()) - s.begin();
    std::cout << ans << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}