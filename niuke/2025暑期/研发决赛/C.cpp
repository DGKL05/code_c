#include <bits/stdc++.h>
using namespace std;
using int =long long;
#define endl '\n'
std::vector<int> g(200010, 0);

void test()
{
    int n = 0, m = 0, k = 0;
    std::cin >> n >> m >> k;
    std::vector<std::vector<int>> arr(m);
    for (int i = 1; i <= n; i++)
    {
        int tmp = 0; std::cin >> tmp;
        arr[i % m].push_back(tmp);
    }
    
    auto calc = [&](std::vector<int>& nums) -> std::pair<int, int>
    {
        
        int mindel = 0, maxdel = 0;
        int cnt = 0; int sum = 0;
        int sz = nums.size();
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < sz; i++)
        {
            g[++cnt] = nums[i];
            sum += nums[i];
        } 
        for (int i = 1; i <= cnt; i++)
        {
            int tar = g[i];
            int l = 0, r = cnt + 1;
            while(l + 1 < r)
            {
                int mid = (l + r) >> 1;
                if (g[mid] < tar)
                {
                    l = mid;
                }
                else
                {
                    r = mid;
                }
            }
            int small = l;
            l = 0, r = cnt + 1;
            while(l + 1 < r)
            {
                int mid = (l + r) >> 1;
                if (g[mid] <= tar)
                {
                    l = mid;
                }
                else
                {
                    r = mid;
                }
            }
            int big = cnt - r + 1;
            int equal = cnt - small - big;
            // 变成0
            int mdel = -tar * (equal + big) + (k - tar) * small;
            // 变成k - 1
            int pdel = (equal + small) * (k - 1 - tar) - big * (tar + 1);
            mindel = std::min(mindel, mdel);
            maxdel = std::max(maxdel, pdel);
        }
        return {sum + mindel, sum + maxdel};
    };
    int res1 = 0, res2 = 0;
    for (int i = 0; i < m; i++)
    {
        auto [t1, t2] = calc(arr[i]);
        // std::cout << t1 << " " << t2 << endl;
        res1 += t1, res2 += t2;
    }
    std::cout << res2 << " " << res1 << endl;
}

signed main() {
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) test();
    return 0;
}