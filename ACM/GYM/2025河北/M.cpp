#include <bits/stdc++.h>
using namespace std;

const int M = 210;
int n, m;
int gold, silvey, bronze;
int gold_number, silvey_number, bronze_number;
bool is_res = false;
vector<int> team;

bool cmp(int a, int b) { return a > b; }

void check(int question) 
{
    int k = __builtin_popcount(question);
    if (k < 10 || k > 13) return;
    vector<int> number_total;
    number_total.reserve(m);
    for (int i = 0; i < m; ++i)
        number_total.push_back(__builtin_popcount(question & team[i]));
    sort(number_total.begin(), number_total.end(), cmp);
    if (number_total[gold - 1] != gold_number)   return;
    if (number_total[silvey - 1] != silvey_number) return;
    if (number_total[bronze - 1] != bronze_number) return;
    cout << k << '\n';
    for (int i = 0; i < n; ++i)
        if ((question >> i) & 1)
            cout << i + 1 << ' ';
    cout << '\n';
    is_res = true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (!(cin >> n >> m)) return 0;
    team.reserve(m);
    for (int i = 0; i < m; ++i) 
    {
        string cnt; cin >> cnt;
        int bm = 0;
        for (int j = 0; j < n; ++j)
            if (cnt[j] == '1')
                bm |= (1 << j);
        team.push_back(bm);
    }
    cin >> gold >> silvey >> bronze
        >> gold_number >> silvey_number >> bronze_number;

    const int FULL = 1 << n;
    for (int mask = 0; mask < FULL; ++mask) 
    {
        if (__builtin_popcount(mask) < gold_number) continue;
        check(mask);
        if (is_res) return 0;
    }
    cout << -1 << '\n';
    return 0;
}
