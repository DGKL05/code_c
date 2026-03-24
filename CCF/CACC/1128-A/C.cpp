#include<bits/stdc++.h>
using namespace std;
using ll =long long;

struct Block {
    vector<long long> vals;
    long long even_sum, odd_sum, total_sum;
    int even_cnt, odd_cnt;
    long long lazy_even, lazy_odd;
    int size;

    Block(int sz) : size(sz) {
        vals.assign(sz, 0);
        even_cnt = sz;
        odd_cnt = 0;
        even_sum = 0;
        odd_sum = 0;
        total_sum = 0;
        lazy_even = 0;
        lazy_odd = 0;
    }
};

int n, m;
int blk_sz, num_blocks;
vector<Block> blocks;

void init_blocks() {
    blk_sz = (int)sqrt(n);
    if (blk_sz == 0) blk_sz = 1;
    num_blocks = (n + blk_sz - 1) / blk_sz;
    blocks.reserve(num_blocks);
    for (int i = 0; i < num_blocks; i++) {
        int start_idx = i * blk_sz;
        int end_idx = min((i + 1) * blk_sz, n) - 1;
        int cur_sz = end_idx - start_idx + 1;
        blocks.emplace_back(cur_sz);
    }
}

void push_down(int block_id) {
    Block& blk = blocks[block_id];
    for (int j = 0; j < blk.size; j++) {
        if (blk.vals[j] % 2 == 0) {
            blk.vals[j] += blk.lazy_even;
        } else {
            blk.vals[j] += blk.lazy_odd;
        }
    }
    blk.lazy_even = 0;
    blk.lazy_odd = 0;
}

void update(int l, int r, int o, long long y) {
    int l0 = l - 1, r0 = r - 1;
    int blk_l = l0 / blk_sz;
    int blk_r = r0 / blk_sz;
    for (int i = blk_l; i <= blk_r; i++) {
        int start_idx = i * blk_sz;
        int end_idx = start_idx + blocks[i].size - 1;
        int L = max(l0, start_idx);
        int R = min(r0, end_idx);
        Block& blk = blocks[i];
        if (L == start_idx && R == end_idx) {
            if (o == 0) {
                if (y % 2 == 0) {
                    blk.even_sum += (long long)blk.even_cnt * y;
                    blk.total_sum += (long long)blk.even_cnt * y;
                    blk.lazy_even += y;
                } else {
                    push_down(i);
                    blk.odd_sum += blk.even_sum + (long long)blk.even_cnt * y;
                    blk.odd_cnt += blk.even_cnt;
                    blk.even_sum = 0;
                    blk.even_cnt = 0;
                    blk.total_sum = blk.odd_sum;
                    for (int j = 0; j < blk.size; j++) {
                        if (blk.vals[j] % 2 == 0) {
                            blk.vals[j] += y;
                        }
                    }
                }
            } else {
                if (y % 2 == 0) {
                    blk.odd_sum += (long long)blk.odd_cnt * y;
                    blk.total_sum += (long long)blk.odd_cnt * y;
                    blk.lazy_odd += y;
                } else {
                    push_down(i);
                    blk.even_sum += blk.odd_sum + (long long)blk.odd_cnt * y;
                    blk.even_cnt += blk.odd_cnt;
                    blk.odd_sum = 0;
                    blk.odd_cnt = 0;
                    blk.total_sum = blk.even_sum;
                    for (int j = 0; j < blk.size; j++) {
                        if (blk.vals[j] % 2 != 0) {
                            blk.vals[j] += y;
                        }
                    }
                }
            }
        } else {
            push_down(i);
            int L0 = L - start_idx;
            int R0 = R - start_idx;
            for (int j = L0; j <= R0; j++) {
                long long old_v = blk.vals[j];
                if ((o == 0 && old_v % 2 == 0) || (o == 1 && old_v % 2 != 0)) {
                    long long new_v = old_v + y;
                    if (old_v % 2 == 0) {
                        blk.even_sum -= old_v;
                        blk.even_cnt--;
                    } else {
                        blk.odd_sum -= old_v;
                        blk.odd_cnt--;
                    }
                    if (new_v % 2 == 0) {
                        blk.even_sum += new_v;
                        blk.even_cnt++;
                    } else {
                        blk.odd_sum += new_v;
                        blk.odd_cnt++;
                    }
                    blk.total_sum += (new_v - old_v);
                    blk.vals[j] = new_v;
                }
            }
        }
    }
}

long long query(int l, int r) {
    int l0 = l - 1, r0 = r - 1;
    int blk_l = l0 / blk_sz;
    int blk_r = r0 / blk_sz;
    long long res = 0;
    for (int i = blk_l; i <= blk_r; i++) {
        int start_idx = i * blk_sz;
        int end_idx = start_idx + blocks[i].size - 1;
        int L = max(l0, start_idx);
        int R = min(r0, end_idx);
        Block& blk = blocks[i];
        if (L == start_idx && R == end_idx) {
            res += blk.total_sum;
        } else {
            push_down(i);
            int L0 = L - start_idx;
            int R0 = R - start_idx;
            for (int j = L0; j <= R0; j++) {
                res += blk.vals[j];
            }
        }
    }
    return res;
}

void test()
{
    cin >> n >> m;
    init_blocks();
    while (m--) {
        int type;
        cin >> type;
        if (type == 0) {
            int s, t, o;
            long long y;
            cin >> s >> t >> o >> y;
            update(s, t, o, y);
        } else {
            int s, t;
            cin >> s >> t;
            cout << query(s, t) << '\n';
        }
    }
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