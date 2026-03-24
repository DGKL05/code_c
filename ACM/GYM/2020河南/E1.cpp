#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
int n;
int k;
typedef pair<LL, int> PII1;
typedef pair<LL, LL> PII2;

#define x first
#define y second

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // int a=(2 ^ 3 ^ 7);
    // int b=(((((2 ^ 3 ^ 7)) ^ 3) ^ 7) );
    // cout << a << ' ' << b << "\n";
    cin >> n >> k;

    vector<PII2> h_v;
    vector<PII1> c_v;
    h_v.reserve(n * 2);
    c_v.reserve(n * 2);

    for (int i = 0; i < n; i ++ )
    {
        LL l, r, w;
        cin >> l >> r >> w;

        h_v.push_back({l    ,  w});
        h_v.push_back({r + 1,  w});
        c_v.push_back({l    ,  1});
        c_v.push_back({r + 1, -1});
    }

    struct Thing
    {
        LL t;
        LL t_res;
        int cnt;
    };
    
    vector<Thing> ev;
    ev.reserve(2 * n);

    
    sort(h_v.begin(), h_v.end());
    sort(c_v.begin(), c_v.end());

    int h_idx = 0, c_idx = 0;
    int h_len = h_v.size(), c_len = c_v.size();
    // cout << h_len << ' ' << c_len << endl;
    LL t_res = 0;
    int t_cnt = 0;
    while (h_idx < h_len || c_idx < c_len)
    {
        LL t;
        if (c_idx >= c_len || (h_idx < h_len) && (h_v[h_idx].x <= c_v[c_idx].x))
            t = h_v[h_idx].x;
        else
            t = c_v[c_idx].x;

        while (h_idx < h_len && t == h_v[h_idx].x) t_res ^= h_v[h_idx ++ ].y;
        while (c_idx < c_len && t == c_v[c_idx].x) t_cnt += c_v[c_idx ++ ].y;
        // cout <<  h_idx << ' ' << t << ' ' << t_res << ' ' <<  t_cnt << endl;
        ev.push_back({t, t_res, t_cnt});
    }

    int total_len = ev.size();

    bool is_res = false;
    LL res = 0;
    LL tt_res = 0;
    t_cnt = 0;
    for (int i = 0; i < total_len; i ++ )
    {
        LL ti = ev[i].t;
        t_cnt = ev[i].cnt;
        tt_res = ev[i].t_res;
        // cout << ti << ' ' << tt_res << ' ' << t_cnt << endl;
        if (t_cnt >= k)
        {
            res = max(res, tt_res);
            is_res = true;
        }

    }

    if (is_res) cout << res << "\n";
    else cout << -1 << "\n";

    return 0;
}
